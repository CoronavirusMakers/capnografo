
#pragma once


struct RecordingSet
{
    const int maxSize = 0;
    float frequency = 0.01f;
    int size = 0;
    float* values = nullptr;


    RecordingSet(int maxSize)
        : maxSize{maxSize}
        , values{new float[maxSize]}
    {}
    ~RecordingSet()
    {
        delete[] values;
    }

    float GetMaximum() const { return 0.f; }
    float GetMinimum() const { return 0.f; }

    float GetNumSamples() const { return size; }
    float GetDuration() const { return frequency * GetNumSamples(); }
};
