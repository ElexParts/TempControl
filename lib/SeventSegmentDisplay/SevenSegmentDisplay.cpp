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

/**
 * Setup segment and display pins.
 */
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
	int digits[2];

	// Set digits.
	digits[0] = num % 10;
	digits[1] = (int) num / 10;

	// Display number.
	for (int i = 0; i < 2; i++) {
		SevenSegmentDisplay::displayDigit(displays[i], digits[i]);
	}
}

/**
 * Display digits.
 */
void SevenSegmentDisplay::displayDigit(int digit, int num) {
	// Set a number to display.
	for (int i = 0; i < 7; i++) {
	  if (type == COMMON_CATHODE) {
      digitalWrite(segments[i], numberMap[num][i]);
    }
    else {
      digitalWrite(segments[i], !numberMap[num][i]);
    }
	}

	// Set which digit to display.
	digitalWrite(digit, LOW);
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
