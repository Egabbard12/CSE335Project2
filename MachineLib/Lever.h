/**
 * @file Lever.h
 * @author Eric Gabbard
 *
 * Lever component for machine
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RectangularComponent.h"
#include "Negotiator.h"
#include "Rod.h"

#include "TranslationSource.h"

class RodSink;

/**
 * The lever component for our machine.
 * Also a negotiator.
 */
class Lever : public Negotiator, public RectangularComponent{
private:
    /// Sink from a rod source
    RodSink mRodSink = RodSink(this);
    /// TranslationSource to drive sinks connected to lever
    TranslationSource mSource = TranslationSource();
    /// Rotation source for lever
    RotationalSource mRotationSource = RotationalSource();
    /// The point for the left end of the lever
    wxPoint mLeftEnd;
public:
    /// Delete default constructor
    Lever() = delete;
    /// Delete default copy constructor
    Lever(const Lever &) = delete;
    /// Delete assignment operator
    void operator=(const Lever &) = delete;

    explicit Lever(double length);

    void UpdateComponent(double param) override;

    void Negotiate(Rod *rod) override;
    /**
     * Getter for Rodsink
     * @return RodSink
     */
    RodSink *GetRodSink(){return &mRodSink;}
    /**
     * Getter for rotation source
     * @return RotationSource
     */
    RotationalSource *GetRotationSource(){return &mRotationSource;}
    /**
     * Getter for Translational source
     * @return Translational source
     */
    TranslationSource *GetTranslationSource(){return &mSource;}
    /**
     * Sets left end lever connection
     * @param point
     */
    void SetLeftEnd(wxPoint point){mLeftEnd = point;}
    /**
     * Getter for left end lever connection
     * @return wxPoint
     */
    wxPoint GetLeftEnd(){return mLeftEnd;}
};


#endif //CANADIANEXPERIENCE_LEVER_H
