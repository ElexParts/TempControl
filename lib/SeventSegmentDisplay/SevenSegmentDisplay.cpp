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
	segments[0] = _segment_a;
	segments[1] = _segment_b;
	segments[2] = _segment_c;
	segments[3] = _segment_d;
	segments[4] = _segment_e;
	segments[5] = _segment_f;
	segments[6] = _segment_g;

	displays[0] = _display_0;
	displays[1] = _display_1;

	type = _type;
}

void SevenSegmentDisplay::begin() {
	// Setup segments.
	for (int i = 0; i < 7; i++) {
		pinMode(segments[i], OUTPUT);
	}

	// Setup displays.
	for (int i = 0; i < 2; i++) {
		pinMode(displays[i], OUTPUT);
	}
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
	// Display second digit.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[num][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[num][i]);
    }
	}
	digitalWrite(displays[0], LOW);
	digitalWrite(displays[1], HIGH);
	delay(1);

	// Clear
	SevenSegmentDisplay::clear();
}

/**
 * Display a digit.
 */
void SevenSegmentDisplay::displaySecondDigit(int num) {
	// Display second digit.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[num][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[num][i]);
    }
	}
	digitalWrite(displays[0], HIGH);
	digitalWrite(displays[1], LOW);
	delay(1);

	// Clear
	SevenSegmentDisplay::clear();
}

/**
 * Clear display.
 */
void SevenSegmentDisplay::clear() {
	for (int i = 0; i < 2; i++) {
		digitalWrite(displays[i], HIGH);
	}
}
