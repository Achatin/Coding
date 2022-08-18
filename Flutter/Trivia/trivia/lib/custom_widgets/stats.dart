import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

import '../constants.dart';

class Stats extends StatelessWidget {
  const Stats({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            SizedBox(
              height: 110,
              width: 85,
              child: DecoratedBox(
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: const BorderRadius.all(Radius.circular(7)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      offset: const Offset(0, 4),
                    ),
                  ],
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Image.asset('assets/images/speaker.png', width: 50),
                    Column(
                      children: [
                        Text('324', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 18, fontWeight: FontWeight.bold))),
                        Text('answered', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                        Text('questions', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                      ],
                    ),
                    const SizedBox(
                      height: 5,
                    ),
                  ],
                ),
              ),
            ),

            SizedBox(
              height: 110,
              width: 85,
              child: DecoratedBox(
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: const BorderRadius.all(Radius.circular(7)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      offset: const Offset(0, 4),
                    ),
                  ],
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Image.asset('assets/images/checkmark.png', width: 50),
                    Column(
                      children: [
                        Text('272', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 18, fontWeight: FontWeight.bold))),
                        Text('correct', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                        Text('answers', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                      ],
                    ),
                    const SizedBox(
                      height: 5,
                    ),
                  ],
                ),
              ),
            ),

            SizedBox(
              height: 120,
              width: 95,
              child: DecoratedBox(
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: const BorderRadius.all(Radius.circular(7)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      offset: const Offset(0, 4),
                    ),
                  ],
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Image.asset('assets/images/lightbulb.png', width: 50),
                    Column(
                      children: [
                        Text('84%', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 18, fontWeight: FontWeight.bold))),
                        Text('success', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                        Text('rate', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                      ],
                    ),
                    const SizedBox(
                      height: 5,
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),

        const SizedBox(
          height: 30,
        ),

        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            SizedBox(
              height: 110,
              width: 85,
              child: DecoratedBox(
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: const BorderRadius.all(Radius.circular(7)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      offset: const Offset(0, 4),
                    ),
                  ],
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Image.asset('assets/images/fire.png', width: 60),
                    Column(
                      children: [
                        Text('12 days', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 18, fontWeight: FontWeight.bold))),
                        Text('streak', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                      ],
                    ),
                    const SizedBox(
                      height: 5,
                    ),
                  ],
                ),
              ),
            ),

            SizedBox(
              height: 110,
              width: 85,
              child: DecoratedBox(
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: const BorderRadius.all(Radius.circular(7)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      offset: const Offset(0, 4),
                    ),
                  ],
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Image.asset('assets/images/crown.png', width: 60),
                    Column(
                      children: [
                        Text('Expert', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 18, fontWeight: FontWeight.bold))),
                        Text('level', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                      ],
                    ),
                    const SizedBox(
                      height: 5,
                    ),
                  ],
                ),
              ),
            ),

            SizedBox(
              height: 110,
              width: 85,
              child: DecoratedBox(
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: const BorderRadius.all(Radius.circular(7)),
                  boxShadow: [
                    BoxShadow(
                      color: Colors.black.withOpacity(0.1),
                      blurRadius: 4,
                      offset: const Offset(0, 4),
                    ),
                  ],
                ),
                child: Column(
                  children: [
                    Image.asset('assets/images/folder.png', width: 60),
                    Column(
                      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                      children: [
                        Text('37 sets', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: dark, fontSize: 18, fontWeight: FontWeight.bold))),
                        Text('completed', style: GoogleFonts.dmSans(textStyle: const TextStyle(color: detail, fontSize: 10, fontWeight: FontWeight.bold))),
                      ],
                    ),
                    const SizedBox(
                      height: 5,
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ],
    );
  }
}