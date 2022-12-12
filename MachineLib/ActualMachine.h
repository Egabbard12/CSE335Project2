/**
 * @file ActualMachine.h
 * @author Eric Gabbard
 *
 * Wrapper class for machine
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

#include "Machine.h"
#include "FunctionalMachine.h"

/**
 * The wrapper class for machine
 */
class ActualMachine : public Machine{
private:
    /// FunctionalMachine for machine
    std::shared_ptr<FunctionalMachine> mFunctionalMachine = nullptr;
    /// Location for actual machine
    wxPoint mActualLocation;
    /// Directory for images of machine parts
    std::wstring mImagesDir;
    /// Framerate for the machine
    double mFrameRate;
    /// Speed for machine
    double mSpeed;
public:
    explicit ActualMachine(std::wstring imagesDir);

    void SetLocation(wxPoint location) override;

    wxPoint GetLocation() override;

     void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

     void SetMachineFrame(int frame) override;

     void SetFrameRate(double rate) override;

     void SetSpeed(double speed) override;

     void SetMachineNumber(int machine) override;

     int GetMachineNumber() override;
};


#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
