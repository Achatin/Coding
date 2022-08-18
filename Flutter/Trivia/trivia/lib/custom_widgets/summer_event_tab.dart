import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import '../constants.dart';


class SummerEventTab extends StatelessWidget {
  const SummerEventTab({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Stack(
      alignment: Alignment.centerRight,
      clipBehavior: Clip.none,
      children: [
        SizedBox(
          width: double.maxFinite,
          height: 130,
          child: DecoratedBox(
            decoration: BoxDecoration(
              color: const Color.fromARGB(255, 226, 157, 71),
              borderRadius: BorderRadius.circular(12),
              boxShadow: const [
                BoxShadow(
                  color: Color.fromARGB(180, 226, 157, 71),
                  offset: Offset(0, 3.5),
                  blurRadius: 6,
                ),
              ],
            ),
            child: Padding(
              padding: const EdgeInsets.fromLTRB(25, 0, 0, 0),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text('Summer', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: lightBG, fontSize: 26, fontWeight: FontWeight.bold))),
                  Text('Event', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: lightBG, fontSize: 26, fontWeight: FontWeight.bold))),
                ],
              ),
            ),
          ),
        ),

        Positioned(
          bottom: -25,
          left: 150,
          child: Image.asset('assets/images/sun.png', width: 190)
        ),
      ],
    );
  }
}