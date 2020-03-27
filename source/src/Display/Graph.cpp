
#include "Display/Graph.h"
#include "Display/Display.h"


void Graph::Draw(Display& screen)
{
    DrawAxis(screen);
    DrawLines(screen);
    DrawLabels(screen);
}

void Graph::DrawAxis(Display& screen) const
{
    DrawLine(screen, {0.f, 0.f},     {0.f, maxY},    COLOR_WHITE);  // Y
    DrawLine(screen, {0.f, 0.f},     {maxX, 0.f},    COLOR_WHITE);  // X
    DrawLine(screen, {0.f, midYBar}, {maxX, midYBar}, COLOR_ORANGE); // Mid Y
}

void Graph::DrawLines(Display& screen) const {}

void Graph::DrawLabels(Display& screen) const
{
    DrawFloat(screen, {0.f, maxY}, maxY, COLOR_WHITE);
    DrawFloat(screen, {0.f, midYBar}, midYBar, COLOR_WHITE);
}

void Graph::DrawLine(Display& screen, v2 a, v2 b, u16 color) const
{
    screen.DrawLine(ToPixel(a), ToPixel(b), color);
}

void Graph::DrawFloat(Display& screen, v2 location, float value, u16 color) const
{
    //const v2i pixel = ToPixel(location);
    //screen.setCursor(pixel.x, pixel.y);
    //screen.setTextColor(color);
    //screen.setTextWrap(true);
    //screen.print(value);
}

v2i Graph::ToPixel(v2 value) const
{
    return {
        position.x + Math::RoundToInt((value.x / maxX) * size.x),
        position.y + Math::RoundToInt((value.y / maxY) * size.y)
    };
}