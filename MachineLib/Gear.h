/**
 * @file Gear.h
 * @author Eric Gabbard
 *
 * The gear class for our machine
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H


#include "RotationalSink.h"
#include "RotationalSource.h"

class Component;

/**
 * The gear class for our machine derived from component
 */
class Gear : public Component {
private:
    /// Radius of gear
    double mRadius;
    /// Number of teeth on gear
    int mNumOfTeeth;
    /// Rotation sink for gear
    RotationalSink mSink = RotationalSink(0,0,this); ///< The rotation sink for this component
    /// Rotational source for gear to pass to sinks
    std::shared_ptr<RotationalSource> mGearSource;
public:
    /// Delete default constructor
    Gear() = delete;
    /// Delete copy constructor
    Gear(const Gear &) = delete;
    /// Delete assignment operator
    void operator=(const Gear &) = delete;

    Gear(double radius, int numTeeth);
    /**
     * Get rotational sink for gear
     * @return rotational sink
     */
    RotationalSink *GetSink(){return &mSink;}
    /**
     * Get source for driving
     * @return rotational source
     */
    RotationalSource *GetSource(){return &*mGearSource;}

    void UpdateComponent(double param) override;

    void SetRotation(double rotation) override;

    void Drive(std::shared_ptr<Gear> gear, double phase);
};


#endif //CANADIANEXPERIENCE_GEAR_H
