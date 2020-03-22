
#include "RecordingSet.h"


class Capnograph;

class AnalysisPattern
{
    Capnograph& cartograph;

    AnalysisPattern(Capnograph& cartograph) : cartograph{cartograph} {}
    virtual ~AnalysisPattern() {}

    virtual bool Analize(const RecordingSet& recording) const {}
    virtual void OnTrigger() const {}
};
