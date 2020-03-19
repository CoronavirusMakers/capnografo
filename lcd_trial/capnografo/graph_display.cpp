#include "graph_display.h"

namespace graph_display
{

GraphDisplay::GraphDisplay(HardwareSerial &print_serial, LiquidCrystal *lcd)
{

  printer_ = &print_serial; //operate on the adress of print
  printer_->begin(115200);
  
  lcd_ = lcd;
  lcd_->begin(16, 2);
}

void
GraphDisplay::step(float value)
{
  /*
   * value: c02 value to print in the graph
   */
   
  printer_->println(value);
  lcd_->setCursor(0, 8);
  lcd_->print(millis() / 1000);
}

};
