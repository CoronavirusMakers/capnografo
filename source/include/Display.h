
#pragma once

#include "Platform.h"
#include "Math/v2.h"
#include "Math/v2i.h"
#include "Display/DisplayTypes.h"
#include "Display/Graph.h"
#include "RecordingSet.h"



class Display
{
    // Should X and Y be flipped?
    static constexpr bool bFlippedAxis = true;

    // Offset to apply to screen positions in some displays.
    // Change it as needed by the target screen
    const v2i offset {1, 2};

    ScreenType screen {5, 2, 4};

    // Real available size of the screen
    const v2i size;

    Graph graph {};

    const float graphDuration = 10.f;


public:

    Display()
        : size{
            i32(screen.height()) - offset.x,
            i32(screen.width())  - offset.y
        }
    {
        graph.position = {0, 0};
        graph.size = {size.x, size.y / 2};
    }

    void Start()
    {
        screen.enableTearing(false);
        screen.initR(INITR_BLACKTAB);
        screen.fillScreen(COLOR_BLACK);
    }

    void Render()
    {
        screen.fillScreen(COLOR_BLACK);
        graph.Draw(*this);
    }

    void SetCurrentCO2(float value) {}
    void UpdateRecording(const RecordingSet& recording) {}

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

    v2i ToScreen(v2i position) const
    {
        position += offset;
        if (bFlippedAxis) // constexpr
        {
            return {position.y, position.x}; // Flip screen
        }
        else
        {
            return position;
        }
    }
};
