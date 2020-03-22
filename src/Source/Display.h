
#include "RecordingSet.h"


class Display
{
    const float graphDuration = 10.f;

    // Highest vertical value in mmHg
    const float graphTopCO2 = 60.f;

    // Maximum healthy CO2 in mmHg
    // Displayed as a vertical line
    const float graphMaxCO2 = 45.f;


    void SetCurrentCO2(float value) {}
    void UpdateRecording(const RecordingSet& recording) {}
};
