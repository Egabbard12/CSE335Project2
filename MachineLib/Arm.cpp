/**
 * @file Arm.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Arm.h"
#include <cmath>

/**
 * Update the component and sinks
 *
 * @param param rotation to be updated to
 */
void Arm::UpdateComponent(double param)
{
    double x = GetPointOfRotation().x + GetLength() * cos(GetRotation() * M_PI * 2)+5;
    double y = GetPointOfRotation().y + GetLength() * sin(GetRotation() * M_PI * 2)+3;
    mEndArm = wxPoint(x,y);
    auto rod = mTransSource.GetComponent();
    rod->SetPosition(x,y);
    mTransSource.UpdateSinks(this);
}

/**
 * Arm to be set to a gear or motor component
 * @param length length of arm
 */
Arm::Arm(double length)
{
    SetLength(length);
    Rectangle(GetPosition().x-6,GetPosition().y-6,length+10, -12);
}
