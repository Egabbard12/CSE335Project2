/**
 * @file MachineAdapter.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "MachineAdapter.h"
#include "machine-api.h"

/**
 * Constructor
 * @param name
 */
MachineAdapter::MachineAdapter(const std::wstring &name) : Drawable(name)
{

}

/**
 * Overridden draw function to scale and draw machine
 * @param graphics
 */
void MachineAdapter::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    double scale = 0.75f;

    graphics->PushState();
    graphics->Translate(GetPosition().x, GetPosition().y);
    graphics->Scale(scale, scale);
    mMachine->SetLocation(wxPoint(0, 0));
    mMachine->DrawMachine(graphics);
    graphics->PopState();

}

/**
 * Initialize default values for machine
 */
void MachineAdapter::Initialize() {
    MachineFactory factory(mImagesDir);

    mMachine = factory.CreateMachine();
   // mMachine->SetMachineNumber(1);
    mMachine->SetMachineFrame(0);
    mMachine->SetFrameRate(30);
    mMachine->SetSpeed(1);
}

/**
 * Sets the current frame for the machine
 * @param frame
 */
void MachineAdapter::SetFrame(int frame)
{
    if (frame >= mStartFrame)
    {
        mMachine->SetMachineFrame(frame);
    }
    else
        mMachine->SetMachineFrame(0);
}

/**
 * Sets the frame to start the machine
 * @param frame
 */
void MachineAdapter::SetStartFrame(int frame)
{
    mStartFrame = frame;
}

/**
 * Sets the Framerate for the machine
 * @param frameRate
 */
void MachineAdapter::SetFrameRate(double frameRate)
{
    mMachine->SetFrameRate(frameRate);
}

/**
 * Dispay the machine dialogue for selecting machine number
 * @param mainFrame
 */
void MachineAdapter::ShowDialogue(wxWindow *mainFrame)
{
    MachineDialog dlg(mainFrame, mMachine);
    if (dlg.ShowModal() == wxID_OK)
    {
        // A machine has been selected
        mMachine->SetMachineFrame(0);
        mMachine->SetFrameRate(30);
        mMachine->SetSpeed(1);
    }
}

/**
 * Overridden Hit test always false as machines are currently
 * not clickable.
 *
 * @param pos position of hit
 * @return bool always false
 */
bool MachineAdapter::HitTest(wxPoint pos) {
    return false;
}

/**
 * Sets the machine number for the machine
 * changing which machine is assigned.
 *
 * @param num integer to set
 */
void MachineAdapter::SetMachineNumber(int num) {
    mMachine->SetMachineNumber(num);
}

/**
 * Overridden Place function sets the location
 * for the machine.
 *
 * @param offset Point to place
 * @param rotate Rotation of the item
 */
void MachineAdapter::Place(wxPoint offset, double rotate) {
    Drawable::Place(offset, rotate);
    mMachine->SetLocation(offset);
}

/**
 * Saves the machine attributes to the passed node
 * @param machineName Which machine to save it for
 * @param node Xml node to save to
 */
void MachineAdapter::SaveMachineData(wxString machineName, wxXmlNode *node)
{
    int num = mMachine->GetMachineNumber();
    std::wstring numStr = std::to_wstring(num);
    node->AddAttribute(machineName + L"Number", numStr);

    std::wstring startFrame = std::to_wstring(mStartFrame);
    node->AddAttribute(machineName + L"StartFrame",startFrame);
}

/**
 * Loads the machine attributes from the passed node
 * @param attributeName Which machine to load to
 * @param node Xml node to load from
 */
void MachineAdapter::LoadMachineData(wxString attributeName, wxXmlNode *node) {
    wxString num = node->GetAttribute(attributeName + L"Number",L"default");
    mMachine->SetMachineNumber(std::atoi(num));
    wxString startFrame = node->GetAttribute(attributeName + L"StartFrame",L"default");
    SetStartFrame(std::atoi(startFrame));
}
