/**
 * @file Arm.h
 * @author Eric Gabbard
 *
 * Arm class for the machine
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "RectangularComponent.h"
#include "RotationalSink.h"
#include "RotationalSource.h"
#include "TranslationSource.h"

/**
 * Arm class for the machine
 *
 * Can be attached to a motor or a gear for
 * rotation. Attaches to a rod or lever on the other
 * end.
 */
class Arm : public RectangularComponent{
private:
    /// The driving end of the arm
    wxPoint mEndArm;
    /// Rotational sink to pass into a rod
    RotationalSink mSink = RotationalSink(0,0,this); ///< The rotation sink for this component
    /// The translational source to pass the rod through
    TranslationSource mTransSource = TranslationSource();
public:
    /// Delete default constructor
    Arm() = delete;
    /// Delete default copy constructor
    Arm(const Arm &) = delete;
    /// Delete assignment operator
    void operator=(const Arm &) = delete;

    explicit Arm(double length);
    void UpdateComponent(double param) override;
    /**
     * Getter for the arm end opposite the driven end
     * @return
     */
    wxPoint GetArmEnd(){return mEndArm;}
    /**
     * Getter for that translation source
     * @return Translation source
     */
    TranslationSource *GetSource(){return &mTransSource;}
    /**
     * Get Rotation sink for the arm
     * @return
     */
    RotationalSink *GetSink(){return &mSink;}
};


#endif //CANADIANEXPERIENCE_ARM_H
