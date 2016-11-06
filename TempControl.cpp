#include <iostream>

using namespace std;

const bool HIGH = 1;

class LedDisplay
{
private:
  int _ledPins [7];
  int _enablePin;
  
  int convertToBinary(int num);
  void digitalWrite(int pin, int state);
  
public:
  LedDisplay () { }
  LedDisplay (int ledPins[7], int enablePin)
  {
    int i;
    for (i = 0; i < 7; i++)
    {
      _ledPins[i] = ledPins[i];
    }
    
    _enablePin = enablePin;
  }
  
  int getEnablePin();
  void getLedPins();
  void display(int num);
};

/**
 * Get the Enable pin.
 */
int LedDisplay::getEnablePin()
{
  return _enablePin;
}

/**
 * Get all LED pins.
 * @todo Return the list of LED pins.
 */
void LedDisplay::getLedPins()
{
  int i;
  
  cout << "The LED pins are : " << endl;
  for (i = 0; i < 7; i++)
  {
    cout << _ledPins[i] << endl;
  }
}

/**
 * Display a number.
 */
void LedDisplay::display(int num)
{
  switch(num)
  {
    case 0 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      digitalWrite(_ledPins[3], HIGH);
      digitalWrite(_ledPins[4], HIGH);
      digitalWrite(_ledPins[5], HIGH);
      break;
    case 1 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      break;
    case 2 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      digitalWrite(_ledPins[4], HIGH);
      digitalWrite(_ledPins[3], HIGH);
      break;
    case 3 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      digitalWrite(_ledPins[3], HIGH);
      break;
    case 4 :
      digitalWrite(_ledPins[5], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      break;
    case 5 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[5], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      digitalWrite(_ledPins[3], HIGH);
      break;
    case 6 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[5], HIGH);
      digitalWrite(_ledPins[4], HIGH);
      digitalWrite(_ledPins[3], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      break;
    case 7 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      break;
    case 8 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      digitalWrite(_ledPins[3], HIGH);
      digitalWrite(_ledPins[4], HIGH);
      digitalWrite(_ledPins[5], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      break;
    case 9 :
      digitalWrite(_ledPins[0], HIGH);
      digitalWrite(_ledPins[5], HIGH);
      digitalWrite(_ledPins[6], HIGH);
      digitalWrite(_ledPins[1], HIGH);
      digitalWrite(_ledPins[2], HIGH);
      break;
  }
}

/**
 * Convert decimal to binary.
 */
int LedDisplay::convertToBinary(int num)
{
  long dec, bin = 0, rem, base = 1;
  
  dec = num;
  while (dec > 0)
  {
    rem = dec % 2;
    bin = bin + rem * base;
    base = base * 10;
    dec = dec / 2;
  }
  
  return bin;
}

/**
 * Mock::digitalWrite()
 */
void LedDisplay::digitalWrite(int pin, int state)
{
  cout << "Pin " << pin << " set to " << state << "." << endl;
}

int main()
{
  // Initialize LED pins.
  int ledPins [7] = {2,3,4,5,6,7,8};
  int enablePin = 9;
  
  // Display a decimal to a 7-Segment LED Display.
  LedDisplay ledDisplay (ledPins, enablePin);
  
  int dec;
  cout << "Please enter number to display: " << endl;
  cin >> dec;
  ledDisplay.display(dec);
  
  return 0;
}
