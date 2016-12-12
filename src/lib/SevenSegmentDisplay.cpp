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

void digitalWrite(int ledPins, int state) {
  //
}

void SevenSegmentDisplay::display(int num) {
  int state;

  if (type == COMMON_ANODE) {
    // Active LOW.
    state = LOW;
  } else {
    // Active HIGH.
    state = HIGH;
  }

  switch(num) {
    case 0 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[2], state);
//      digitalWrite(ledPins[3], state);
//      digitalWrite(ledPins[4], state);
//      digitalWrite(ledPins[5], state);
      break;
    case 1 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[1], state);
      break;
    case 2 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[6], state);
//      digitalWrite(ledPins[4], state);
//      digitalWrite(ledPins[3], state);
      break;
    case 3 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[6], state);
//      digitalWrite(ledPins[2], state);
//      digitalWrite(ledPins[3], state);
      break;
    case 4 :
//      digitalWrite(ledPins[5], state);
//      digitalWrite(ledPins[6], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[2], state);
      break;
    case 5 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[5], state);
//      digitalWrite(ledPins[6], state);
//      digitalWrite(ledPins[2], state);
//      digitalWrite(ledPins[3], state);
      break;
    case 6 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[5], state);
//      digitalWrite(ledPins[4], state);
//      digitalWrite(ledPins[3], state);
//      digitalWrite(ledPins[2], state);
//      digitalWrite(ledPins[6], state);
      break;
    case 7 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[2], state);
      break;
    case 8 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[2], state);
//      digitalWrite(ledPins[3], state);
//      digitalWrite(ledPins[4], state);
//      digitalWrite(ledPins[5], state);
//      digitalWrite(ledPins[6], state);
      break;
    case 9 :
//      digitalWrite(ledPins[0], state);
//      digitalWrite(ledPins[5], state);
//      digitalWrite(ledPins[6], state);
//      digitalWrite(ledPins[1], state);
//      digitalWrite(ledPins[2], state);
      break;
  }
}
