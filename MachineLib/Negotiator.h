/**
 * @file Negotiator.h
 * @author Eric Gabbard
 *
 * Used to Negotiate between two components
 */

#ifndef CANADIANEXPERIENCE_NEGOTIATOR_H
#define CANADIANEXPERIENCE_NEGOTIATOR_H

#include"RectangularComponent.h"

class Rod;
/**
 * Negotiates between two components
 */
class Negotiator{
private:

public:
    Negotiator() = default;
    /**
     * Negotiate with a rod to come up with a mutual rotation solution
     * @param rod
     */
    virtual void Negotiate(Rod *rod) = 0;
};


#endif //CANADIANEXPERIENCE_NEGOTIATOR_H
