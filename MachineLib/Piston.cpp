/**
 * @file Piston.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Piston.h"
#include "Lever.h"
#include "Rod.h"

// all offsets below are to balance a shift in the machine
/// offset to position Y to line up with lever
int rodOffsetY=-217;
/// Offset to position x to line up with lever
int rodOffsetX= 11;
/// Piston Offset to line up with rod
int pistonOffsetX= -220;
/// Rotation offset to position connection of rod and piston
double rodRotationOffset=.05;

/**
 * Negotiate between piston and rod
 * @param rod
 */
void Piston::Negotiate(Rod *rod) {

    auto lever = mRodSink.GetLever();

    int x1 = lever->GetLeftEnd().x;
    int y1 = lever->GetLeftEnd().y;

    int x2 = GetPosition().x;

    double a = rod->GetLength();

    double y2 = y1+a;

    double alpha = asin((x2-x1)/a);
    double beta = (M_PI/2)-alpha;

    rod->SetRotation(beta*.159155+rodRotationOffset);
    SetPosition(x2,int(y2)+pistonOffsetX);

    rod->SetPosition(lever->GetLeftEnd().x+rodOffsetX,lever->GetLeftEnd().y+rodOffsetY);
}

/**
 * Updates component and sinks
 * @param param
 */
void Piston::UpdateComponent(double param) {
    Component::UpdateComponent(param);
    Component::SetRotation(param);
    mSource.UpdateSinks(this);
}

/**
 * Constructor
 */
Piston::Piston()
{
    mRodSink.SetNegotiator(this);
    SetRotationPoint(wxPoint(0,0));
}
