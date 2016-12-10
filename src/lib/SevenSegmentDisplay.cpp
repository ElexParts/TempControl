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
