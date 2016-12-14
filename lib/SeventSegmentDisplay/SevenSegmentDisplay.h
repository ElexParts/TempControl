//============================================================================
// Name        : SevenSegmentDisplay.h
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

#ifndef ELEXPROJECT_SEVENSEGMENTDISPLAY_H
#define ELEXPROJECT_SEVENSEGMENTDISPLAY_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define COMMON_CATHODE 0
#define COMMON_ANODE 1

class SevenSegmentDisplay
{
private:
  int segments[7];
  int displays[2];
  int type;

  const bool numberMap[10][7] {
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}, // 9
  };

public:
  SevenSegmentDisplay (
    int _segment_a,
  	int _segment_b,
  	int _segment_c,
  	int _segment_d,
  	int _segment_e,
  	int _segment_f,
    int _segment_g,
  	int _display_0,
  	int _display_1,
  	int _type = COMMON_CATHODE
  );

  void begin();
  void display(int num);
  void displayFirstDigit(int num);
  void displaySecondDigit(int num);
  void clear();
};

#endif
