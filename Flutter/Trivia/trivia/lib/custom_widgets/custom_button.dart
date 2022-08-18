import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_fonts/google_fonts.dart';

import '../screens/results.dart';
import '../constants.dart';
import '../controllers/controller.dart';

class CustomButton extends StatelessWidget {
  final text;
  final answNo;
  const CustomButton({Key? key, this.text, this.answNo}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final data = Get.find<QuestionController>();
    return GestureDetector(
      onTap: () {
        if (data.isAnswered.value == false) {
          data.revealAnswer(answNo);
          Future.delayed(Duration(seconds: 3), () {
            if (data.questionNo < 10) {
              data.nextQuestion();
              data.isAnswered(false);
            } else {
              Get.off(const ResultsPage());
            }
          });
        }
      },
      child: SizedBox(
          width: double.maxFinite,
          height: 50,
          child: Obx(
            () => DecoratedBox(
              decoration: BoxDecoration(
                border: (data.answerStates[answNo] == 3 ||
                        data.answerStates[answNo] == 4)
                    ? Border.all(color: lightBG, width: 0)
                    : Border.all(color: dark),
                color: (data.answerStates[answNo] == 3)
                    ? lightBlue
                    : (data.answerStates[answNo] == 4)
                        ? lightRed
                        : Colors.transparent,
                borderRadius: BorderRadius.circular(10),
              ),
              child: Center(
                  child: Obx(() => Text(text,
                      style: GoogleFonts.dmSans(
                          textStyle: TextStyle(
                              color: (data.answerStates[answNo] == 3 || data.answerStates[answNo] == 4) ? lightBG : dark, fontWeight: (data.answerStates[answNo] == 3 || data.answerStates[answNo] == 4) ? FontWeight.bold : FontWeight.normal, fontSize: 18))))),
            ),
          )),
    );
  }
}
