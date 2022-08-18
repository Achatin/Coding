import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:trivia/screens/home.dart';

import '../constants.dart';
import '../controllers/controller.dart';

class ResultsPage extends StatelessWidget {
  const ResultsPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final data = Get.find<QuestionController>();
    return Scaffold(
      backgroundColor: lightBlue,
      body: Column(
        children: [

          Padding(
            padding: const EdgeInsets.all(40.0),
            child: Row(
              children: [
                Image.asset('assets/images/logo.png', width: 32),
                Text(' Trivia', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontWeight: FontWeight.bold, fontSize: 28))),
              ],
            ),
          ),

          Expanded(child: Image.asset('assets/images/trophy.png', width: 230)),

          Expanded(
            child: SizedBox(
            width: double.maxFinite,
            child: DecoratedBox(
                decoration: BoxDecoration(
                  color: lightBG,
                  borderRadius: const BorderRadius.only(topLeft: Radius.circular(40), topRight: Radius.circular(40)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      spreadRadius: 4,
                      offset: const Offset(0, -1),
                    ),
                  ],
                ),
                child: Padding(
                  padding: const EdgeInsets.all(40.0),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [

                      Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text('set complete', style: GoogleFonts.dmSans(textStyle: const TextStyle( color: detail, fontSize: 18, fontWeight: FontWeight.bold))),
                          Text('Congratulations!', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 30, fontWeight: FontWeight.bold))),
                        ],
                      ),

                      Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            children: [
                              Text('Correct', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 20, fontWeight: FontWeight.bold))),
                              const Text(''),
                              Text('Rewards', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 20, fontWeight: FontWeight.bold))),
                            ],
                          ),

                          Column(
                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                            children: [
                              Text('....................', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 20, fontWeight: FontWeight.bold))),
                              const Text(''),
                              Text('....................', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 20, fontWeight: FontWeight.bold))),
                            ],
                          ),

                          Column(
                            children: [
                              Obx(() => Text('${data.correctAnswers} / 10', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 20, fontWeight: FontWeight.bold)))),
                              const Text(''),
                              Row(
                                children: [
                                  Obx(() => Text('+${data.correctAnswers}', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 20, fontWeight: FontWeight.bold)))),
                                  Image.asset('assets/images/medal.png', width: 45),
                                ],
                              ),
                            ],
                          ),
                        ],
                      ),

                      GestureDetector(
                        onTap: () => Get.off(const HomePage()),
                        child: SizedBox(
                          width: double.maxFinite,
                          height: 50,
                          child: DecoratedBox(
                            decoration: const BoxDecoration(
                              color: lightBlue,
                              borderRadius: BorderRadius.all(Radius.circular(10)),
                            ),
                            child: Center(child: Text('Continue', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: lightBG, fontSize: 18, fontWeight: FontWeight.bold)))),
                          ),
                        ),
                      ),

                    ],
                  ),
                ),
              ),
            ),
          ),

        ],
      ),
    );
  }
}