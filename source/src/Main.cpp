
#include <Arduino.h>

#include "Capnograph.h"


Capnograph captograph {};

void setup()
{
    captograph.Setup();
}

void loop()
{
    captograph.Loop();
}
