#ifndef GRAPH_DISPLAY_H
#define GRAPH_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

namespace graph_display
{

class GraphDisplay
{

public:

  GraphDisplay(HardwareSerial &print_serial, LiquidCrystal *lcd);

  void step(float value);

private:

  HardwareSerial *printer_;
  LiquidCrystal *lcd_;

};

};

//int addTwoInts(int a, int b);


#endif
