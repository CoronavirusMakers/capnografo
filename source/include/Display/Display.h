
#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include "Platform.h"
#include "Math/v2.h"
#include "Math/v2i.h"
#include "DisplayTypes.h"
#include "Graph.h"
#include "RecordingSet.h"


class Display
{
protected:

    //~ BEGIN Display Settings
    using ScreenType = Adafruit_ST7735;
    
    // Should X and Y be flipped?
    static constexpr bool bFlippedAxis = true;

    // Offset to apply to screen positions in some displays.
    // Change it as needed by the target screen
    const v2i offset {1, 2};

    ScreenType screen {5, 2, 4}; // CS, RS, RST
    //~ END Display Settings

public:

    // Real available size of the screen
    const v2i size;


    Display()
        : size {
            i32(screen.height()) - offset.x,
            i32(screen.width())  - offset.y
        }
    {}

    void Start()
    {
        screen.enableTearing(false);
        screen.initR(INITR_BLACKTAB);
        FillColor(COLOR_BLACK);
    }

    void FillColor(u16 color)
    {
        screen.fillScreen(color);
    }

    void DrawPixel(v2i position, u16 color)
    {
        position = ToScreen(position);
        screen.drawPixel(position.x, position.y, color);
    }

    void DrawLine(v2i a, v2i b, u16 color)
    {
        a = ToScreen(a);
        b = ToScreen(b);
        screen.drawLine(a.x, a.y, b.x, b.y, color);
    }

    v2i ToScreen(v2i position) const;
};
