#include <LiquidCrystal.h>
#include "graph_display.h"

void setup() {
  Serial.begin(115200);
}

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //( RS, EN, d4, d5, d6, d7)

graph_display::GraphDisplay gd(Serial, &lcd);

float i = 0.0;
void loop() {
  
  gd.step(i+=0.5);
  delay(200);
 
}
