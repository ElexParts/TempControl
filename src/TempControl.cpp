//============================================================================
// Name        : TempControl.cpp
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

#include <iostream>
#include <vector>
#include "lib/SevenSegmentDisplay.h"

using namespace std;

int main() {
  // The read temperature.
  float temperature;

  // Configure 7 segment pins.
  vector<int> ledPins (7);
  ledPins[0] = 3;
  ledPins[1] = 4;
  ledPins[2] = 5;
  ledPins[3] = 6;
  ledPins[4] = 7;
  ledPins[5] = 8;
  ledPins[6] = 9;

  // Configure LED displays.
  vector<int> displays (4);
  displays[0] = 12;
  displays[1] = 11;

  // Initialize a 7-Segment Display.
  SevenSegmentDisplay sevenSegmentDisplay(ledPins, displays, COMMON_ANODE);

  // Display temperature.
  temperature = (int) 26.0;
  sevenSegmentDisplay.display(temperature);

	return 0;
}
