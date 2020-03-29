
#pragma once


class SensorAdapter {};

class Sensor
{
public:
    float lastValue = 0.f;

    Sensor() {}
    virtual ~Sensor() {}
    virtual void Record(RecordingSet& record) = 0;
};

class Sensor_SprintIR : public Sensor {};

class Sensor_MockAnalog : public Sensor
{
    static constexpr u32 pin = 34;
    static constexpr float minValue = 0.f;
    static constexpr float maxValue = 60.f;


public:

    virtual void Record(RecordingSet& record) override
    {
        // Read signal 4 times and average value
        u16 value = 0;
        for(u8 i = 0; i < 4; ++i)
        {
            value += analogRead(pin);
            delayMicroseconds(50);
        }
        value /= 4;
        
        // Record value
        const float value01 = float(value) / 4096;
        lastValue = minValue + (value01 * (maxValue - minValue));

        record.RecordValue(lastValue);
    }
};
