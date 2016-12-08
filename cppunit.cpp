#include <iostream>
#include "SevenSegmentDisplay.h"

using namespace std;

int main()
{
  int ledPins;
  
  SevenSegmentDisplay sevenSegmentDisplay(5, 3);
  
  ledPins = sevenSegmentDisplay.getLedPins();
  
  cout << ledPins << endl;
}
