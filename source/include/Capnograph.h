
#include <vector>
#include <memory>

#include "Alarm.h"
#include "Display.h"
#include "Sensor.h"
#include "Pattern.h"
#include "AllPatterns.h"


class Capnograph
{
    Alarm alarm;
    Display display;
    Sensor sensor;

    // List of patterns
    std::vector<std::unique_ptr<AnalysisPattern>> analysisPatterns;


    Capnograph()
    {
        // The order of registration implies order of priority.
        // First registered is higher priority
        RegisterPattern<Pattern_Hiperventilation>();
        RegisterPattern<Pattern_Hipoventilation>();
    }

    template<typename T>
    T& RegisterPattern()
    {
        analysisPatterns.push_back(std::make_unique<T>(*this));
        return *analysisPatterns.back().get();
    }
};