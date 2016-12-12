#include <iostream>
#include "lib/SevenSegmentDisplay.h"

using namespace std;

int main() {
  int ledPins;

  SevenSegmentDisplay sevenSegmentDisplay(5, 3, COMMON_ANODE);

  ledPins = sevenSegmentDisplay.getLedPins();
  cout << ledPins << endl;
  sevenSegmentDisplay.display(8);

	return 0;
}
