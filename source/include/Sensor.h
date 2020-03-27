
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
        u16 iValue = analogRead(pin);
        Serial.println(iValue);

        const float value01 = float(iValue) / 4096;
        lastValue = minValue + (value01 * (maxValue - minValue));
    }
};
