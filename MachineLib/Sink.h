/**
 * @file Sink.h
 * @author Eric Gabbard
 *
 * Base sink class
 */

#ifndef CANADIANEXPERIENCE_SINK_H
#define CANADIANEXPERIENCE_SINK_H

#include "Component.h"

/**
 * Base Sink class for updating components
 */
class Sink {
private:
    /// The Offset between the source and the driven component
    double mPhase = 0;
    /// Speed to move the component
    double mSpeed = 1;
    /// Pointer to component owned by this sink
    Component *mComponent;
public:
    /// Delete default constructor
    Sink() = delete;
    /// Delete copy constructor
    Sink(const Sink &) = delete;
    /// Delete assignment operator
    void operator=(const Sink &) = delete;
    /**
     * Constructor
     * @param component that owns this sink
     */
    explicit Sink(Component *component){ mComponent = component;}

    /**
     * Getter for component
     * @return component this sink belongs to
     */
     Component *GetComponent(){return mComponent;}
    /**
     * sets the speed for this sink to pass on
     * @param speed
     */
    void SetSpeed(double speed){mSpeed = speed;}
    /**
     * Getter for speed
     * @return double speed
     */
     double GetSpeed(){return mSpeed;}
    /**
     * Setter for the offset between the driving component
     * and the component that owns this sink.
     *
     * @param phase
     */
    void SetPhase(double phase){mPhase = phase;}
    void UpdateComponentTranslation(Component *component);

};


#endif //CANADIANEXPERIENCE_SINK_H
