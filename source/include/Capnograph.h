
#pragma once

#include "Alarm.h"
#include "Display.h"
#include "Sensor.h"
#include "Pattern.h"
#include "AllPatterns.h"


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


    void Setup()
    {
        SetupPatterns();
        display.Start();
    }

    void Loop() {
        display.Render();
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
