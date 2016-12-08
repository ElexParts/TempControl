#include <iostream>

using namespace std;

class SevenSegmentDisplayTest
{
  #define COMMON_ANODE 1
  
  /**
   * Test that Seven Segment LED Display shows a correct number.
   */
  public function testDisplay()
  {
    // Instantiate a new SevenSegmentDisplay object.
    list pins = [
      a => 2,
      b => 3,
    ];
    debug = true;
    SevenSegmentDisplay sevenSegmentDisplay(pins, this::COMMON_ANODE, debug);
    
    // Display numbers from 0 to 9.
    for (i=0; i<10; i++) {
      sevenSegmentDisplay->display(i);
      
      // Check the display.
      displayedNumber = this->getDisplay();
      
      // Verify that correct number was displayed.
      this->assertEquals(displayedNumber, i);
    }
  }
}
