import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:circular_countdown_timer/circular_countdown_timer.dart';
import 'package:trivia/custom_widgets/technology_tab.dart';

import '../controllers/controller.dart';
import '../custom_widgets/custom_button.dart';
import '../constants.dart';

class QuestionPage extends StatefulWidget {
  QuestionPage({Key? key}) : super(key: key);

  @override
  State<QuestionPage> createState() => _QuestionPageState();
}

class _QuestionPageState extends State<QuestionPage> {
  final CountDownController _controller = CountDownController();

  @override
  Widget build(BuildContext context) {
    final data = Get.find<QuestionController>();
    return Scaffold(
      backgroundColor: lightBG,
      body: Padding(
        padding: const EdgeInsets.all(40.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Row(
              children: [
                Image.asset('assets/images/logo.png', width: 32),
                Text(' Trivia', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontWeight: FontWeight.bold, fontSize: 28))),
              ],
            ),
            /*Center(
              child: CircularCountDownTimer(
                duration: 10,
                initialDuration: 0,
                controller: _controller,
                width: 50,
                height: 50,
                ringColor: dark,
                ringGradient: null,
                fillColor: lightBlue,
                fillGradient: null,
                backgroundColor: Colors.transparent,
                backgroundGradient: null,
                strokeWidth: 5.0,
                strokeCap: StrokeCap.round,
                textStyle: GoogleFonts.dmSans(
                    textStyle: const TextStyle(
                        color: dark,
                        fontSize: 14,
                        fontWeight: FontWeight.bold)),
                textFormat: CountdownTextFormat.SS,
                isReverse: true,
                isReverseAnimation: false,
                isTimerTextShown: true,
                autoStart: true,
                onComplete: () {
                  if (data.questionNo.value <= 10) {
                    //data.nextQuestion();
                    //_controller.restart();
                  }
                },
              ),
            ),*/
            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Obx(() => Text('question ${data.questionNo} of 10', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: detail, fontSize: 17, fontWeight: FontWeight.bold)))),
                const Text(''),
                Obx(() => Text(data.questionSet[data.questionNo.value-1]['question'], style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontSize: 26, fontWeight: FontWeight.bold)))),
              ],
            ),
            Column(
              children: [
                Obx(() => CustomButton(text: data.answers[0], answNo: 0)),
                const Text(''),
                Obx(() => CustomButton(text: data.answers[1], answNo: 1)),
                const Text(''),
                Obx(() => CustomButton(text: data.answers[2], answNo: 2)),
                const Text(''),
                Obx(() => CustomButton(text: data.answers[3], answNo: 3)),
              ],
            ),
            const Text(''),
          ],
        ),
      ),
    );
  }
}
