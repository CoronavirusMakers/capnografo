
#include "UI.h"
#include "Capnograph.h"


void UI::Start()
{
    display.Start();

    graph.position = {0, 0};
    const v2i size = display.GetSize();
    graph.size = {size.x, size.y / 2};
}

void UI::Draw(Capnograph& capnograph)
{
    display.FillColor(COLOR_BLACK);
    graph.Draw(display, capnograph.record);

    //Axis tests
    //display.DrawPixel({0, 0}, COLOR_CYAN);
    //display.DrawPixel({0, 100}, COLOR_MAGENTA);
    //display.DrawPixel({100, 0}, COLOR_RED);

    DrawCurrentValue(capnograph);
}

void UI::DrawCurrentValue(Capnograph& capnograph)
{
    const float value = capnograph.sensor.lastValue;

    u16 color = COLOR_WHITE;
    if(value > graph.midYBar)
    {
        color = COLOR_RED;
    }
    else if(value > graph.midYBar * 0.7f)
    {
        color = COLOR_YELLOW;
    }

    display.SetCursor({10, display.GetSize().y - 10});
    display.SetTextSize(4);
    display.SetTextColor(color, COLOR_BLACK);
    display.Print(value, 0);
}
