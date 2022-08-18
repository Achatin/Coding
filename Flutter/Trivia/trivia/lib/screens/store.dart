import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:google_fonts/google_fonts.dart';

import '../constants.dart';


class StorePage extends StatelessWidget {
  const StorePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
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
    );
  }
}