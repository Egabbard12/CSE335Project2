/**
 * @file RotationalSink.h
 * @author Eric Gabbard
 *
 * Updates rotation from a RotationalSource
 */

#ifndef CANADIANEXPERIENCE_ROTATIONALSINK_H
#define CANADIANEXPERIENCE_ROTATIONALSINK_H

#include "Component.h"
#include "Sink.h"

/**
 * Updates rotation from a RotationalSource
 */
class RotationalSink : public Sink{
private:
public:
    /// Delete default constructor
    RotationalSink() = delete;
    /// Delete copy constructor
    RotationalSink(const RotationalSink &) = delete;
    /// Delete assignment operator
    void operator=(const RotationalSink &) = delete;

    RotationalSink(double ratio, double phase,Component *component);

    void UpdateComponent(double ratio, double phase);

};


#endif //CANADIANEXPERIENCE_ROTATIONALSINK_H
