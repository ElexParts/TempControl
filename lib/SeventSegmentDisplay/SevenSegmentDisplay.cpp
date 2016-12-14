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
	int _type
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
	// Setup segments.
	pinMode(segment_a, OUTPUT);
	pinMode(segment_b, OUTPUT);
	pinMode(segment_c, OUTPUT);
	pinMode(segment_d, OUTPUT);
	pinMode(segment_e, OUTPUT);
	pinMode(segment_f, OUTPUT);
	pinMode(segment_g, OUTPUT);

	// Setup displays.
	pinMode(display_0, OUTPUT);
	pinMode(display_1, OUTPUT);
}

/**
 * Display a number.
 */
void SevenSegmentDisplay::display(int num) {
	// Set digits.
	int firstDigit = num % 10;
	int secondDigit = (int) num / 10;

	// Display number.
	SevenSegmentDisplay::displayFirstDigit(firstDigit);
	SevenSegmentDisplay::displaySecondDigit(secondDigit);
}

/**
 * Display a digit.
 */
void SevenSegmentDisplay::displayFirstDigit(int num) {
	int segments[7] = {
		segment_a,
		segment_b,
		segment_c,
		segment_d,
		segment_e,
		segment_f,
		segment_g
	};

	// Display second digit.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[num][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[num][i]);
    }
	}
	digitalWrite(display_0, LOW);
	digitalWrite(display_1, HIGH);
	delay(1);

	// Clear
	SevenSegmentDisplay::clear();
}

/**
 * Display a digit.
 */
void SevenSegmentDisplay::displaySecondDigit(int num) {
	int segments[7] = {
		segment_a,
		segment_b,
		segment_c,
		segment_d,
		segment_e,
		segment_f,
		segment_g
	};

	// Display second digit.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[num][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[num][i]);
    }
	}
	digitalWrite(display_0, HIGH);
	digitalWrite(display_1, LOW);
	delay(1);

	// Clear
	SevenSegmentDisplay::clear();
}

/**
 * Clear display.
 */
void SevenSegmentDisplay::clear() {
	digitalWrite(display_0, HIGH);
	digitalWrite(display_1, HIGH);
}
