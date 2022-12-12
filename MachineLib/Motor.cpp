/**
 * @file Motor.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Motor.h"
#include "RotationalSource.h"

/**
 * Constructor
 * @param machine Machine the motor belongs to
 */
Motor::Motor(ActualMachine *machine)
{
    mMotorSource = std::make_shared<RotationalSource>();
}

/**
 * Sets the time for the motor
 * @param time double calculated in ActualMachine
 */
void Motor::SetTime(double time) {
    mRotation = mSpeed * time;
    mShaftPolygon.SetRotation(mRotation);
    mMotorSource->SetRotation(mRotation);
    mMotorSource->UpdateSinks();
}

/**
 * Updates the motorComponent
 * @param param double to update component with
 */
void Motor::UpdateComponent(double param) {
    Component::UpdateComponent(param);


}

/**
 * Draws the motor and shaft
 * @param graphics wxGraphics for machine
 * @param x x coordinate to draw from
 * @param y y coordinate to draw from
 */
void Motor::DrawComponent(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if (!mShaftFront)
    {
        auto position = GetPosition();
        mShaftPolygon.DrawPolygon(graphics, x + position.x, y + position.y);
        Component::DrawComponent(graphics, x, y);
    }
    else
    {
        auto position = GetPosition();
        Component::DrawComponent(graphics, x, y);
        mShaftPolygon.DrawPolygon(graphics, x + position.x, y + position.y);
    }
}

/**
 * Sets the shaft image for the motor
 * @param filename image directory for shaft
 */
void Motor::SetShaftImage(std::wstring filename)
{
    mShaftPolygon.CenteredSquare(65);
    mShaftPolygon.SetImage(filename);
}
