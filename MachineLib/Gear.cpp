/**
 * @file Gear.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Gear.h"
#include "Component.h"
#include <cmath>

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down

/**
 * The gear component for our machine
 * @param radius radius of gear
 * @param numTeeth Number of teeth on gear
 */
Gear::Gear(double radius, int numTeeth)
{
    mGearSource = std::make_shared<RotationalSource>();
    mRadius = radius;
    mNumOfTeeth = numTeeth;

    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;
    double PI2= M_PI * 2;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
}

/**
 * Update the component source and sinks
 * @param param rotation double
 */
void Gear::UpdateComponent(double param)
{
    mGearSource->SetRotation(param);
    mGearSource->UpdateSinks();
}

/**
 * Sets the Rotation for the gear
 * @param rotation
 */
void Gear::SetRotation(double rotation) {

    Component::SetRotation(rotation);
}

/**
 * Drives the gear
 * @param gear the gear being driven
 * @param phase the offset for distance between driver
 */
void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();

    mGearSource->AddSink(sink);
    sink->SetSpeed(-(double)mNumOfTeeth / (double)gear->mNumOfTeeth);
    sink->SetPhase(phase);
}
