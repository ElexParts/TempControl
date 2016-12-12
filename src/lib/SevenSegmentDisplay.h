#ifndef ELEXPROJECT_SEVENSEGMENTDISPLAY_H
#define ELEXPROJECT_SEVENSEGMENTDISPLAY_H

#define COMMON_CATHODE 0
#define COMMON_ANODE 1
#define LOW 0
#define HIGH 1

class SevenSegmentDisplay
{
private:
  std::vector<int> ledPins;
  std::vector<int> displays;
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
  SevenSegmentDisplay (std::vector<int> _ledPins, std::vector<int> _displays, int _type = COMMON_CATHODE);
  
  std::vector<int> getLedPins();
  std::vector<int> getDisplays();
  int getType();
  void setLedPins(std::vector<int> ledPins);
  void setDisplays(std::vector<int> displays);
  void setType(int type);

  void display(int num);
};

#endif
