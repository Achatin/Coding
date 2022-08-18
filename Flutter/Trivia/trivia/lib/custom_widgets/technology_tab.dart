import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import '../constants.dart';


class TechnologyTab extends StatelessWidget {
  const TechnologyTab({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Stack(
      alignment: Alignment.topCenter,
      clipBehavior: Clip.none,
      children: [
        SizedBox(
          width: 140,
          height: 220,
          child: DecoratedBox(
            decoration: BoxDecoration(
              color: const Color.fromARGB(255, 255, 100, 7),
              borderRadius: BorderRadius.circular(12),
              boxShadow: const [
                BoxShadow(
                  color: Color.fromARGB(180, 255, 100, 7),
                  offset: Offset(0, 3.5),
                  blurRadius: 6,
                ),
              ],
            ),
            child: Align(
              alignment: Alignment.bottomCenter,
              child: Padding(
                padding: const EdgeInsets.fromLTRB(0, 0, 0, 30),
                child: Text('Technology', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: lightBG, fontSize: 22, fontWeight: FontWeight.bold))),
              )
            ),
          ),
        ),



        Positioned(
          bottom: 60,
          left: -40,
          child: Image.asset('assets/images/processor.png', width: 250),
        ),

      ],
    );
  }
}