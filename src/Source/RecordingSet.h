
#include <vector>


struct RecordingSet
{
    float frequency = 0.01f;

    std::vector<float> values;


    float GetMaximum() const { return 0.f; }
    float GetMinimum() const { return 0.f; }

    float GetSamples() const { return values.size(); }
    float GetDuration() const { return frequency * GetSamples(); }
};
