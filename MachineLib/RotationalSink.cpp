/**
 * @file RotationalSink.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "RotationalSink.h"

/**
 * Constructor
 * @param ratio rotation to set
 * @param phase offset to pass
 * @param component Component that owns this sink
 */

RotationalSink::RotationalSink(double ratio, double phase,Component *component) : Sink(component)
{
    SetPhase(phase);
}

/**
 * updates component rotation, offset, and reversed bool
 * @param ratio
 * @param phase
 */
void RotationalSink::UpdateComponent(double ratio, double phase) {
    SetPhase(phase);
    ratio = ratio * GetSpeed() + phase ;//+ startingRotationOffset;

    GetComponent()->SetRotation(ratio);
    GetComponent()->UpdateComponent(ratio);

}
