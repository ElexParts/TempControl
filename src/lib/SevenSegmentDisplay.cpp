#include <iostream>

using namespace std;

#include "SevenSegmentDisplay.h"

SevenSegmentDisplay::SevenSegmentDisplay (int _ledPins, int _commonPin, int _type)
{
	ledPins = _ledPins;
	commonPin = _commonPin;
	type = _type;
}

int SevenSegmentDisplay::getLedPins() {
	return ledPins;
}

int SevenSegmentDisplay::getCommonPin() {
	return commonPin;
}

int SevenSegmentDisplay::getType() {
	return type;
}

void SevenSegmentDisplay::setLedPins(int _ledPins) {
  ledPins = _ledPins;
}

void SevenSegmentDisplay::setCommonPin(int _commonPin) {
  commonPin = _commonPin;
}

void SevenSegmentDisplay::setType(int _type) {
  type = _type;
}
