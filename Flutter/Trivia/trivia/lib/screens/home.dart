import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:circular_countdown_timer/circular_countdown_timer.dart';
import 'package:trivia/custom_widgets/standard_tab.dart';
import 'package:trivia/custom_widgets/summer_event_tab.dart';
import 'package:trivia/custom_widgets/technology_tab.dart';
import 'package:trivia/screens/game.dart';
import 'package:trivia/screens/statistics.dart';
import 'package:trivia/screens/store.dart';

import '../controller_bindings.dart';
import '../controllers/controller.dart';
import '../constants.dart';


class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final data = Get.find<QuestionController>();
    return Scaffold(
      backgroundColor: lightBG,
      body: Padding(
        padding: const EdgeInsets.fromLTRB(35, 35, 35, 15),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Row(
              children: [
                Image.asset('assets/images/logo.png', width: 32),
                Text(' Trivia', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontWeight: FontWeight.bold, fontSize: 28))),
              ],
            ),

            Column(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [

                GestureDetector(
                  child: const StandardTab(),
                  onTap: () async {
                    await data.createQuestionSet();
                    Get.to(QuestionPage());
                  },
                ),

                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Padding(
                      padding: const EdgeInsets.fromLTRB(0, 20, 0, 15),
                      child: Text('Special', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontWeight: FontWeight.bold, fontSize: 22))),
                    ),
                    const SummerEventTab(),
                  ],
                ),

                Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Padding(
                      padding: const EdgeInsets.fromLTRB(0, 20, 0, 15),
                      child: Text('Daily Sets', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontWeight: FontWeight.bold, fontSize: 22))),
                    ),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: const [
                        TechnologyTab(),
                        TechnologyTab(),
                      ],
                    ),
                  ],
                ),

              ],
            ),

            Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: [
                GestureDetector(
                  onTap: () => Get.to(() => const StatisticsPage()),
                  child: Image.asset('assets/icons/statistics_icon.png', width: 32)
                ),
                Image.asset('assets/icons/home_icon.png', width: 35),
                GestureDetector(
                  onTap: () => Get.to(() => const StorePage()),
                  child: Image.asset('assets/icons/shop_icon.png', width: 32)
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}