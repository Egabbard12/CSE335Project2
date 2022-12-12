/**
 * @file Lever.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Lever.h"
#include "RodSink.h"
/// Constant to convert radians to rotations
double rotationConversion = .159155;
/// Height for lever to come out proportional
double leverHeight = 50;
/// Y coordinate to rotate lever from
int rotationPointY = -15;
/**
 * Constructor
 * @param length length of lever
 */
Lever::Lever(double length)
{

    Component::UpdateComponent(length);

    SetLength(length+1);

    Rectangle(-length/2+5,GetPosition().y + 25,length, leverHeight);

    mRodSink.SetNegotiator(this);

    SetRotationPoint(wxPoint(0,rotationPointY));
}

/**
 * Negotiate position and rotation for lever and rod
 * @param rod connected rod
 */
void Lever::Negotiate(Rod *rod) {
    rod->SetEndRod(rod->GetConnectedArm()->GetArmEnd());
    double x2 = GetPointOfRotation().x;
    double y2 = GetPointOfRotation().y;

    double y1 = (rod->GetEndRod().y)+GetLength()/2+20;
    double x1 = rod->GetEndRod().x;
    double a = x2+ GetLength()/2;

    double b = rod->GetLength();

    double c = sqrt(pow((y2-y1),2) +
                    pow((x2-x1),2));

    double s = atan2(-(y2-y1),x2-x1);

    double alpha = acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));

    double theta = s - alpha;
    auto x3 = x1+b*cos(-theta);
    auto y3 = y1+b*sin(-theta);

    rod->SetRotation(-theta*rotationConversion);

    SetLeftEnd(wxPoint(-x3,y2-(y3-y2)));

    UpdateComponent(atan2((y3 - y2),(x3-x2))*rotationConversion);
}

/**
 * Update lever and all components driven by lever
 * @param param
 */
void Lever::UpdateComponent(double param) {
    Component::UpdateComponent(param);
    Component::SetRotation(param);
    mSource.UpdateSinks(this);
}
