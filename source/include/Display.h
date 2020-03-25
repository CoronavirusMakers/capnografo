
#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include "RecordingSet.h"

// Some ready-made 16-bit ('565') color settings
// TODO: Move to a FColor struct
#define COLOR_BLACK   0x0000
#define COLOR_WHITE   0xFFFF
#define COLOR_RED     0xF800
#define COLOR_GREEN   0x07E0
#define COLOR_BLUE    0x001F
#define COLOR_CYAN    0x07FF
#define COLOR_MAGENTA 0xF81F
#define COLOR_YELLOW  0xFFE0
#define COLOR_ORANGE  0xFC00

class Display
{
    Adafruit_ST7735 lcd{5, 2, 4};

    const float graphDuration = 10.f;

    // Highest vertical value in mmHg
    const float graphTopCO2 = 60.f;

    // Maximum healthy CO2 in mmHg
    // Displayed as a vertical line
    const float graphMaxCO2 = 45.f;

public:

    void Start()
    {
        lcd.initR(INITR_BLACKTAB);
        
        lcd.fillScreen(COLOR_BLACK);
    }

    void Render()
    {
        lcd.fillScreen(COLOR_BLACK);
        lcd.drawLine(0, 0, 127, 159, COLOR_GREEN);
        delay(500);
        lcd.fillScreen(COLOR_BLACK);
        lcd.drawLine(0, 159, 127, 0, COLOR_GREEN);
        delay(500);
    }

    void SetCurrentCO2(float value) {}
    void UpdateRecording(const RecordingSet& recording) {}
};
