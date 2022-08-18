import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_fonts/google_fonts.dart';

import '../constants.dart';
import '../custom_widgets/stats.dart';


class StatisticsPage extends StatelessWidget {
  const StatisticsPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: lightBlue,
      body: Column(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          // L O G O
          Padding(
            padding: const EdgeInsets.all(40.0),
            child: Row(
              children: [
                Image.asset('assets/images/logo.png', width: 32),
                Text(' Trivia', style: GoogleFonts.dmSans( textStyle: const TextStyle( color: dark, fontWeight: FontWeight.bold, fontSize: 28))),
              ],
            ),
          ),

          // B G   I M A G E
          Expanded(child: Image.asset('assets/images/graph.png', width: 180)),

          // S T A T S
          Expanded(
            flex: 2,
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
                  padding: const EdgeInsets.fromLTRB(35, 35, 35, 15),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [

                      Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text('analyzed', style: GoogleFonts.dmSans(textStyle: const TextStyle( color: detail, fontSize: 18, fontWeight: FontWeight.bold))),
                          Text('Statistics', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 30, fontWeight: FontWeight.bold))),
                        ],
                      ),

                      const Stats(),

                      // N A V I G A T I O N   B A R
                      Row(
                        mainAxisAlignment: MainAxisAlignment.spaceAround,
                        children: [
                          Image.asset('assets/icons/statistics_icon.png', width: 32),
                          GestureDetector(
                            onTap: () => Get.back(),
                            child: Image.asset('assets/icons/home_icon.png', width: 35)),
                          Image.asset('assets/icons/shop_icon.png', width: 32),
                        ],
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