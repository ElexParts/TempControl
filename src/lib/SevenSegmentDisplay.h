#ifndef SEVENSEGMENTDISPLAY_H
#define SEVENSEGMENTDISPLAY_H

#define COMMON_CATHODE 0
#define COMMON_ANODE 1
#define LOW 0
#define HIGH 1

class SevenSegmentDisplay
{
private:
  int ledPins;
  int commonPin;
  int type;
  
public:
  SevenSegmentDisplay (int _ledPins, int _commonPin, int _type = COMMON_CATHODE);
  
  int getLedPins();
  int getCommonPin();
  int getType();
  void setLedPins(int ledPins);
  void setCommonPin(int commonPin);
  void setType(int type);

  void display(int num);
  void digitalWrite(int ledPins, int state);
};

#endif
