/**
 * @file ActualMachine.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "ActualMachine.h"

#include <utility>
#include "MachineOneFactory.h"
#include "MachineTwoFactory.h"

/**
 * Set the position for the root of the machine
 * @param location The x,y location to place the machine
 */
void ActualMachine::SetLocation(wxPoint location) {
    mActualLocation = location;
    Machine::SetLocation(location);
    mFunctionalMachine->SetLocation(location);
}

/**
 * Get the location of hte machine
 * @return Location x,y in pixels as a point
 */
wxPoint ActualMachine::GetLocation() {
    return Machine::GetLocation();
}

/**
 * Draw the machine at the currently specified location
 * @param graphics Graphics object to render to
 */
void ActualMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) {
    mFunctionalMachine->DrawMachine(graphics,mActualLocation.x,mActualLocation.y);
}

/**
 * Set the current machine animation frame
 * @param frame Frame number
 */
void ActualMachine::SetMachineFrame(int frame) {
    Machine::SetMachineFrame(frame);
    double time = frame / mFrameRate * mSpeed;
    if (mFunctionalMachine)
        mFunctionalMachine->SetMotorTime(time);
}

/**
 * Set the expected frame rate in frames per second
 * @param rate Frame rate in frames per second
 */
void ActualMachine::SetFrameRate(double rate) {
    mFrameRate = rate;
    Machine::SetFrameRate(rate);
}

/**
 * Set  the bend angleGetM
 * @param speed Speed from 0 to 1, where 1 is full speed
 */
void ActualMachine::SetSpeed(double speed) {
    mSpeed = speed;
    Machine::SetSpeed(speed);
}

/**
 * Set the machine number
 * @param machine An integer number. Each number makes a different machine
 */
void ActualMachine::SetMachineNumber(int machine) {
    if (machine == 1)
    {
        auto factory = MachineOneFactory(mImagesDir);
        mFunctionalMachine = factory.Create(this,mImagesDir);
    }
    else if (machine == 2)
    {
        auto factory = MachineTwoFactory(mImagesDir);
        mFunctionalMachine = factory.Create(this,mImagesDir);
    }
    Machine::SetMachineNumber(machine);
}

/**
 * Get the current machine number
 * @return Machine number integer
 */
int ActualMachine::GetMachineNumber() {
    return Machine::GetMachineNumber();
}

/**
 * Constructor
 * @param imagesDir images directory for machine
 */
ActualMachine::ActualMachine(std::wstring imagesDir) {
    mImagesDir = std::move(imagesDir);
    SetMachineNumber(1);
}
