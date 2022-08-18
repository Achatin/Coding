import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import '../constants.dart';


class StandardTab extends StatelessWidget {
  const StandardTab({Key? key}) : super(key: key);

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
              color: const Color.fromARGB(255, 31, 26, 157),
              borderRadius: BorderRadius.circular(12),
              boxShadow: const [
                BoxShadow(
                  color: Color.fromARGB(180, 31, 26, 157),
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
                  Text('Standard', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: lightBG, fontSize: 26, fontWeight: FontWeight.bold))),
                  Text('random', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: Color.fromARGB(255, 158, 168, 193), fontSize: 16, fontWeight: FontWeight.bold))),
                  Text('questions', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: Color.fromARGB(255, 158, 168, 193), fontSize: 16, fontWeight: FontWeight.bold))),
                ],
              ),
            ),
          ),
        ),

        Positioned(
          right: -10,
          child: Image.asset('assets/images/book.png', width: 190)
        ),
        
      ],
    );
  }
}