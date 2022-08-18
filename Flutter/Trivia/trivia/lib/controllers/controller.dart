import 'dart:convert';
import 'dart:math';

import 'package:get/get.dart';
import 'package:http/http.dart' as http;

/*
  * ENUM
  * unanswered: 0
  * correctHidden: 1
  * wrongHidden: 2
  * correct: 3
  * wrong: 4
*/

class APIcontroller extends GetxController {
  List<Map<String, dynamic>> questionSet = [];
  var isLoading = true.obs;

  Future<void> fetchSetData() async {
    final response = await http.get(Uri.parse('https://the-trivia-api.com/api/questions?limit=10&difficulty=easy'));

    if (response.statusCode == 200) {
      questionSet = List<Map<String, dynamic>>.from(jsonDecode(response.body));
      isLoading.value = false;
    } else {
      Get.snackbar('Error Loading Question!', 'Server responded: ${response.statusCode}:${response.reasonPhrase}');
    }
  }
}

class QuestionController extends GetxController {
  var api = APIcontroller();
  List<Map<String, dynamic>> questionSet = [];

  var questionNo = 1.obs;
  var isAnswered = false.obs;
  var correctAnswers = 0.obs;
  var medals = 0.obs;

  var answers = <String>[].obs;
  var answerStates = <int>[0, 0, 0, 0].obs;

  Future<void> createQuestionSet() async {
    await api.fetchSetData();
    questionNo(1);
    isAnswered(false);
    correctAnswers(0);
    questionSet = api.questionSet;
    setAnswers();
  }

  void nextQuestion() {
    questionNo(questionNo.value + 1);
    setAnswers();
  }

  void revealAnswer(int answNo) {
    isAnswered(true);
    // find correct
    int index = answerStates.indexWhere((element) => element == 1);
    // reveal correct
    answerStates.setAll(index, [3]);
    // show your option as wrong
    if (answerStates[answNo] == 2) {
      answerStates.setAll(answNo, [4]);
    }

    if (index == answNo) {
      correctAnswers(correctAnswers.value + 1);
      medals(medals.value + 1);
    }
  }

  void setAnswers() {
    // choose correct answer
    var rng = Random();
    int randomNumber = rng.nextInt(4);
    // set answers
    switch (randomNumber) {
      case 0:
        answers.assignAll([
          api.questionSet[questionNo.value - 1]['correctAnswer'],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][0],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][1],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][2],
        ]);
        answerStates.assignAll([1, 2, 2, 2]);
        break;
      case 1:
        answers.assignAll([
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][0],
          api.questionSet[questionNo.value - 1]['correctAnswer'],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][1],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][2],
        ]);
        answerStates.assignAll([2, 1, 2, 2]);
        break;
      case 2:
        answers.assignAll([
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][0],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][1],
          api.questionSet[questionNo.value - 1]['correctAnswer'],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][2],
        ]);
        answerStates.assignAll([2, 2, 1, 2]);
        break;
      case 3:
        answers.assignAll([
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][0],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][1],
          api.questionSet[questionNo.value - 1]['incorrectAnswers'][2],
          api.questionSet[questionNo.value - 1]['correctAnswer'],
        ]);
        answerStates.assignAll([2, 2, 2, 1]);
        break;
    }
  }
}
