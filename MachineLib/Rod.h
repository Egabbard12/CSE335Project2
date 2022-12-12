/**
 * @file Rod.h
 * @author Eric Gabbard
 *
 * Rod Component for machine
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include"Component.h"
#include"RectangularComponent.h"
#include"RotationalSink.h"
#include "RodSink.h"
#include "Negotiator.h"
#include "TranslationSource.h"
#include "TranslationSink.h"
#include "Arm.h"

/**
 * Rod Component for the machine
 */
class Rod : public RectangularComponent{
private:
    /// End point of the rod connecting to driven component
    wxPoint mEndRod;
    /// The connected arm if one is connected
    std::shared_ptr<Arm> mConnectedArm = nullptr;
    /// Rotational Sink
    RotationalSink mSink = RotationalSink(0,0,this); ///< The rotation sink for this component
    /// Translational source
    TranslationSource mSource = TranslationSource();
    /// Translational sink
    TranslationSink mTranslationSink = TranslationSink(this);
    /// Rodsinkpointer to driven piston or lever
    RodSink *mRodSink = nullptr;
public:
    /// Delete default constructor
    Rod() = delete;
    /// Delete default copy constructor
    Rod(const Rod &) = delete;
    /// Delete assignment operator
    void operator=(const Rod &) = delete;

    void UpdateComponentTranslation(Component *component) override;

    Rod(double length);

    Rod(double length,double width);

    void SetRodSink(RodSink *rodSink);

    /**
     * Getter for source
     * @return *TranslationSource
     */
    TranslationSource *GetSource(){return &mSource;}
    /**
     * Getter for translation sink
     * @return pointer to translation sink
     */
    TranslationSink *GetTranslationSink(){return &mTranslationSink;}
    /**
     * Getter for RodSink
     * @return *RodSink
     */
    RodSink *GetRodSink(){return mRodSink;}

    void SetEndRod(wxPoint point);
    /**
     * Getter for the point at end of the rod
     * @return wxPoint
     */
    wxPoint GetEndRod(){return mEndRod;}
    /**
     * Sets the connected arm
     * @param arm
     */
    void SetConnectedArm(std::shared_ptr<Arm> arm){mConnectedArm = arm;}
    /**
     * Gets connected arm if set Null_ptr if none exists
     * @return
     */
    std::shared_ptr<Arm> GetConnectedArm(){return mConnectedArm;}

};


#endif //CANADIANEXPERIENCE_ROD_H
