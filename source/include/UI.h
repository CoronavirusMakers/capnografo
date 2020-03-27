
#pragma once

#include "Display/Display.h"
#include "Display/Graph.h"


class UI
{
public:

    Display display;
    Graph graph;

    const float graphDuration = 10.f;


    UI()
    {
        graph.position = {0, 0};
        graph.size = {display.size.x, display.size.y / 2};
    }

    void Start()
    {
        display.Start();
    }

    void Draw()
    {
        display.FillColor(COLOR_BLACK);
        graph.Draw(display);
    }
    
    void SetCurrentCO2(float value) {}
    void UpdateRecording(const RecordingSet& recording) {}
};