
#pragma once

#include "Platform.h"
#include "Math/v2.h"
#include "Math/v2i.h"

#include "DisplayTypes.h"


class Display;

struct Graph
{
    float midYBar = 45.f;
    float maxY = 55.f;
    float maxX = 10.f;

    u32 leftMargin = 10;
    v2i position {10, 10};
    v2i size {60, 15};


    Graph() = default;

    // Draws all the components of the graph
    void Draw(Display& display);

    void DrawAxis(Display& display) const;

    void DrawLines(Display& display) const;

    void DrawLabels(Display& display) const;

    void DrawLine(Display& display, v2 a, v2 b, u16 color) const;

    void DrawFloat(Display& display, v2 location, float value, u16 color, u32 digits = 2) const
    {
        DrawFloat(display, ToPixel(location), value, color, digits);
    }
    void DrawFloat(Display& display, v2i pixel, float value, u16 color, u32 digits = 2) const;

private:

    // Convert graph values to screen positions
    v2i ToPixel(v2 value) const;
};
