
#pragma once

#include "Alarm.h"
#include "Display.h"
#include "Sensor.h"
#include "Pattern.h"
#include "AllPatterns.h"
#include "Display/FrameTime.h"


class Capnograph
{
public:

    Alarm alarm;
    Display display;
    Sensor sensor;

    Pattern_Hiperventilation pattern_hiperventilation;
    Pattern_Hipoventilation pattern_hipoventilation;
    // List of patterns. First is higher priority.
    AnalysisPattern* analysisPatterns[2] {&pattern_hiperventilation, &pattern_hipoventilation};

    FrameTime frame;


    void Setup()
    {
        frame.SetFPSCap(20);

        SetupPatterns();
        display.Start();
    }

    void Loop() {
        frame.Tick();
        display.Render();

        Serial.println(frame.GetFPS());
        frame.PostTick();
    }

    static constexpr int GetNumPatterns() { return sizeof(analysisPatterns) / sizeof(AnalysisPattern*); }

protected:

    void SetupPatterns()
    {
        for(auto* pattern : analysisPatterns)
        {
            pattern->Setup(this);
        }
    }
};
