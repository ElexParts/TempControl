//============================================================================
// Name        : SevenSegmentDisplay.cpp
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

#include "SevenSegmentDisplay.h"

/**
 * Construct a new 7-Segment Display.
 */
SevenSegmentDisplay::SevenSegmentDisplay (
	int _segment_a,
	int _segment_b,
	int _segment_c,
	int _segment_d,
	int _segment_e,
	int _segment_f,
	int _segment_g,
	int _display_0,
	int _display_1,
	int _type = COMMON_CATHODE
) {
	segment_a = _segment_a;
	segment_b = _segment_b;
	segment_c = _segment_c;
	segment_d = _segment_d;
	segment_e = _segment_e;
	segment_f = _segment_f;
	segment_g = _segment_g;
	display_0 = _display_0;
	display_1 = _display_1;
	type = _type;
}

void SevenSegmentDisplay::begin() {
	pinMode(segment_a, OUTPUT);
	pinMode(segment_b, OUTPUT);
	pinMode(segment_c, OUTPUT);
	pinMode(segment_d, OUTPUT);
	pinMode(segment_e, OUTPUT);
	pinMode(segment_f, OUTPUT);
	pinMode(segment_g, OUTPUT);
	pinMode(display_0, OUTPUT);
	pinMode(display_1, OUTPUT);
}

/**
 * Display a number.
 */
void SevenSegmentDisplay::display(int num) {
	int segments[7] = {
		segment_a,
		segment_b,
		segment_c,
		segment_d,
		segment_e,
		segment_f,
		segment_g
	};
	int firstDigit;
	int secondDigit;

	// Serial.print("\nNumber: ");
	// Serial.print(num);
	// Serial.print("\n");

	// Set digits.
	firstDigit = num % 10;
	secondDigit = (int) num / 10;

	// Serial.print("\n1st Digit: ");
	// Serial.print(firstDigit);
	// Serial.print("\n2nd Digit: ");
	// Serial.print(secondDigit);
	// Serial.print("\n");

	// Display first digit.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[firstDigit][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[firstDigit][i]);
    }
	}
	digitalWrite(display_0, LOW);
	digitalWrite(display_1, HIGH);
	delay(1);

	// Clear
	digitalWrite(display_0, HIGH);
	digitalWrite(display_1, HIGH);

	// Display second digit.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[secondDigit][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[secondDigit][i]);
    }
	}
	digitalWrite(display_0, HIGH);
	digitalWrite(display_1, LOW);
	delay(1);

	// Clear
	digitalWrite(display_0, HIGH);
	digitalWrite(display_1, HIGH);

  // Display first digit.
  // number = num % 10;
	// if (type == COMMON_CATHODE) {
	// 	digitalWrite(display_0, HIGH);
	// }
	// else {
	// 	digitalWrite(display_0, LOW);
	// }

  // Display second digit.
  // number = (int) num / 10;

  // Display a number.
	// int segments[7] = {
	// 	segment_a,
	// 	segment_b,
	// 	segment_c,
	// 	segment_d,
	// 	segment_e,
	// 	segment_f,
	// 	segment_g
	// };
	//
  // for (int segment = 0; segment < 7; segment++) {
  //   if (type == COMMON_CATHODE) {
  //     digitalWrite(segments[segment], numberMap[number][segment]);
  //   }
  //   else {
  //     digitalWrite(segments[segment], !numberMap[number][segment]);
  //   }
  // }
}
