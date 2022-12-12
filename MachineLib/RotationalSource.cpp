/**
 * @file RotationalSource.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "RotationalSource.h"
#include "RotationalSink.h"

/**
 * Updates sinks to the given rotation and phase
 */
void RotationalSource::UpdateSinks()
{
    for (auto sink : mSinks)
    {
        sink->UpdateComponent(mRotation,0);
    }
}
