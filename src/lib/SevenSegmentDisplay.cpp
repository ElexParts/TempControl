#include <iostream>
#include <vector>

using namespace std;

#include "SevenSegmentDisplay.h"

/**
 * Construct a new 7-Segment Display.
 */
SevenSegmentDisplay::SevenSegmentDisplay (vector<int> _ledPins, vector<int> _displays, int _type)
{
	ledPins = _ledPins;
	displays = _displays;
	type = _type;
}

/**
 * Get LED pins.
 */
vector<int> SevenSegmentDisplay::getLedPins() {
	return ledPins;
}

/**
 * Get displays.
 */
vector<int> SevenSegmentDisplay::getDisplays() {
	return displays;
}

/**
 * Get the type of display.
 */
int SevenSegmentDisplay::getType() {
	return type;
}

/**
 * Set the LED pins.
 */
void SevenSegmentDisplay::setLedPins(vector<int> _ledPins) {
  ledPins = _ledPins;
}

/**
 * Set the displays.
 */
void SevenSegmentDisplay::setDisplays(vector<int> _displays) {
  displays = _displays;
}

/**
 * Set the type.
 */
void SevenSegmentDisplay::setType(int _type) {
  type = _type;
}

/**
 * Display a number.
 */
void SevenSegmentDisplay::display(int num) {
  int number;

  // Display first digit.
  number = num % 10;

  // Display second digit.
  // number = (int) num / 10;

  // Display a number.
  for (int segment = 0; segment < 7; segment++) {
    if (type == COMMON_CATHODE) {
      digitalWrite(ledPins[segment], numberMap[number][segment]);
    }
    else {
      digitalWrite(ledPins[segment], !numberMap[number][segment]);
    }
  }
}
