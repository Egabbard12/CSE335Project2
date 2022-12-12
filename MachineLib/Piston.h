/**
 * @file Piston.h
 * @author Eric Gabbard
 *
 * Piston component for the machine
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H
#include "RectangularComponent.h"
#include "Negotiator.h"
#include "RodSink.h"
#include "TranslationSource.h"
#include "Arm.h"

/**
 * Piston component for the machine
 */
class Piston : public RectangularComponent, public Negotiator{
private:
    /// Rodsink for the piston
    RodSink mRodSink = RodSink(this);
    /// Translation source for piston
    TranslationSource mSource = TranslationSource();
public:
    Piston();

    void UpdateComponent(double param) override;

    void Negotiate(Rod *rod) override;
    /**
     * Get pistons Rodsink
     * @return RodSink
     */
    RodSink *GetRodSink(){return &mRodSink;}
    /**
     * Get Translation source
     * @return TranslationSource
     */
    TranslationSource *GetTranslationSource(){return &mSource;}
};


#endif //CANADIANEXPERIENCE_PISTON_H
