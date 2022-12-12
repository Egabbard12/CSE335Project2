/**
 * @file Motor.h
 * @author Eric Gabbard
 *
 * Motor component for machine
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "ActualMachine.h"
#include "RotationalSource.h"

/**
 * Motor component for machine
 */
class Motor : public Component{
private:
    /// True if motor is running
    bool mIsRunning = false;
    /// Speed for motor
    double mSpeed = 0;
    /// Rotation for motor
    double mRotation = 0;
    /// Shaft Polygon for motor
    Polygon mShaftPolygon;
    /// Determines whether to draw shaft at front or back of motor
    bool mShaftFront = false;
    /// Rotational source for motor to pass to sinks
    std::shared_ptr<RotationalSource> mMotorSource;
public:
    /// Delete default constructor
    Motor() = delete;
    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;
    /// Assignment operator
    void operator=(const Motor &) = delete;

    explicit Motor(ActualMachine *machine);

    void UpdateComponent(double param) override;

    void SetTime(double time);
    /**
     * Sets speed for motor
     *
     * @param speed double representing speed
     */
    void SetMotorSpeed(double speed){mSpeed = speed;}

    void DrawComponent(std::shared_ptr<wxGraphicsContext> graphics,int x,int y) override;

    void SetShaftImage(std::wstring filename);
    /**
     * Sets the mShaftFront to true
     */
    void SetShaftFront(){mShaftFront = true;}
    /**
     * Get motor source
     * @return rotational source
     */
    std::shared_ptr<RotationalSource> GetSource(){return mMotorSource;}

};


#endif //CANADIANEXPERIENCE_MOTOR_H
