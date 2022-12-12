/**
 * @file RodSink.h
 * @author Eric Gabbard
 *
 * Sink for rod Driven components
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H


#include "Component.h"
#include "Negotiator.h"
#include "TranslationSink.h"


class Rod;

class Lever;

class Piston;

/**
 * Sink for rod Driven Components
 */
class RodSink {
private:
    /// Rod driving into the sink
    Rod *mRod = nullptr;
    /// Lever that may be driven
    Lever *mLever = nullptr;
    /// Piston that may be driven
    Piston *mPiston = nullptr;
    /// The Negotiating class to find position
    Negotiator *mNegotiator;
public:

    explicit RodSink(Component *component);
    void Negotiate(Rod *rod);
    /**
     * Setter for lever if being driven
     * @param lever
     */
    void SetLever(Lever *lever){mLever = lever;}
    /**
     * Setter for piston if being driven
     * @param piston
     */
    void SetPiston(Piston *piston){mPiston = piston;}
    /**
     * Setter for the class negotiating (Either piston or lever)
     * @param negotiator
     */
    void SetNegotiator(Negotiator *negotiator){ mNegotiator = negotiator;}
    /**
     * Sets the rod that will be passed to negotiator
     * @param rod
     */
    void SetRod(Rod *rod){mRod = rod;}
    /**
     * Getter for rod
     * @return
     */
    Rod *GetRod(){return mRod;}
    /**
     * Getter for lever
     * @return
     */
    Lever *GetLever(){return mLever;}
};


#endif //CANADIANEXPERIENCE_RODSINK_H
