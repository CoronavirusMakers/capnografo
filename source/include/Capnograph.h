
#pragma once

#include "Alarm.h"
#include "UI.h"
#include "Sensor.h"
#include "Pattern.h"
#include "AllPatterns.h"
#include "Display/FrameTime.h"


class Capnograph
{
public:

    Alarm alarm;
    UI ui;
    Sensor& sensor{ realSensor };

    Pattern_Hiperventilation pattern_hiperventilation;
    Pattern_Hipoventilation pattern_hipoventilation;
    // List of patterns. First is higher priority.
    AnalysisPattern* analysisPatterns[2] {&pattern_hiperventilation, &pattern_hipoventilation};

    RecordingSet record {2000};
    FrameTime frame;

private:

    Sensor_MockAnalog realSensor;


public:

    void Setup()
    {
        frame.SetFPSCap(20);
        SetupPatterns();
        ui.Start();
    }

    void Loop() {
        frame.Tick();

        sensor.Record(record);
        ui.Draw(*this);
        //Serial.println(frame.GetFPS());
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
