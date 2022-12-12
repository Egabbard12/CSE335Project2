/**
 * @file MachineAdapter.h
 * @author Eric Gabbard
 *
 *  Adapter class for machine
 */

#ifndef CANADIANEXPERIENCE_MACHINEADAPTER_H
#define CANADIANEXPERIENCE_MACHINEADAPTER_H

#include "Drawable.h"


class Machine;

/**
 * This class follows the encapsulation adapter
 * pattern. It also inherits from Drawable.
 */
class MachineAdapter : public Drawable{
private:
    /// Machine this adapter is connected to
    std::shared_ptr<Machine> mMachine;
    /// Image directory to pass to factories
    std::wstring mImagesDir;
    /// Frame to start machine at
    int mStartFrame = 0;
public:
    MachineAdapter() = delete;
    /// Delete default copy constructor
    MachineAdapter(const MachineAdapter &) = delete;
    /// Delete assignment operator
    void operator=(const MachineAdapter &) = delete;
    
    explicit MachineAdapter(const std::wstring &name);

    bool HitTest(wxPoint pos) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * Sets the image Directory to a member variable
     * @param imagesDir
     */
    void SetImagesDir(std::wstring imagesDir){mImagesDir = imagesDir;}

    void Initialize();

    void SetFrame(int frame);

    void SetFrameRate(double frameRate);

    void ShowDialogue(wxWindow *mainFrame);

    void Place(wxPoint offset, double rotate) override;

    void SetMachineNumber(int num);

    void SetStartFrame(int frame);

    void SaveMachineData(wxString machineName, wxXmlNode *node);

    void LoadMachineData(wxString attributeName, wxXmlNode *node);
    
};


#endif //CANADIANEXPERIENCE_MACHINEADAPTER_H
