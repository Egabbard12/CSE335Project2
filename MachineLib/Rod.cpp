/**
 * @file Rod.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Rod.h"

/// Screen offset to shift components
int offset = 5;
/**
 * Constructor
 * @param length
 */
Rod::Rod(double length)
{
    SetLength(length);
}

/**
 * Setter for RodSink
 * @param rodSink
 */
void Rod::SetRodSink(RodSink *rodSink)
{
    mRodSink = rodSink;
    rodSink->SetRod(this);

}

/**
 * Set the point for the end of the rod
 * @param point
 */
void Rod::SetEndRod(wxPoint point)
{
    mEndRod = wxPoint(point.x+offset,point.y);
}

/**
 * Constructor for length and width
 * @param length
 * @param width
 */
Rod::Rod(double length, double width)
{
    Rectangle(0,-width/2,length,width);
    SetLength(length);
    SetHeight(width);
    SetRotationPoint(wxPoint(0,-width/2));
}

/**
 * Negotiate the position and rotation
 * @param component
 */
void Rod::UpdateComponentTranslation(Component *component)
{
    mRodSink->Negotiate(this);
}
