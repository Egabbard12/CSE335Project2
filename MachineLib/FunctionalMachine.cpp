/**
 * @file FunctionalMachine.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "FunctionalMachine.h"
#include "Component.h"
#include "Motor.h"

/**
 * Call draw on each machine component
 * @param graphics graphics for machine
 * @param x x coordinate for the machine
 * @param y y coordinate for the machine
 */
void FunctionalMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics,int x,int y) {
    for (auto component : mComponents)
    {
        component->DrawComponent(graphics,x,y);
    }
}

/**
 * Sets the location for the machine
 * @param location location for the machine
 */
void FunctionalMachine::SetLocation(wxPoint location)
{
    mPoint = location;
}

/**
 * Sets the motor time for each frame
 * @param time The current time the machine is at
 */
void FunctionalMachine::SetMotorTime(double time)
{
    for (const auto& motor : mMotors)
    {
        motor->SetTime(time);
    }

}

/**
 * Add component to machine
 * @param component part for machine
 */
void FunctionalMachine::AddComponent(std::shared_ptr<Component> component) {
    mComponents.push_back(component);
}
