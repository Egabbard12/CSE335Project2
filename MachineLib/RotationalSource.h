/**
 * @file RotationalSource.h
 * @author Eric Gabbard
 *
 * Class to represent the source of
 * rotation for all child components
 */

#ifndef CANADIANEXPERIENCE_ROTATIONALSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONALSOURCE_H

class Component;
class RotationalSink;

/**
 * Represents the source of rotation for all child components
 */
class RotationalSource {
private:
    /// Rotation to pass down
    double mRotation;
    /// The speed to pass down
    double mSpeed;
    /// Vector of sinks to update
    std::vector<RotationalSink *> mSinks;

public:
    RotationalSource() = default;
    /// Copy constructor (disabled)
    RotationalSource(const RotationalSource &) = delete;
    /// Assignment operator (disabled)
    void operator=(const RotationalSource &) = delete;

    void UpdateSinks();
    /**
     * Set the rotation for the source to update sinks to
     * @param rotation
     */
    void SetRotation(double rotation){mRotation = rotation;}
    /**
     * Add a sink for this source to update
     * @param sink
     */
    void AddSink(RotationalSink *sink){mSinks.push_back(sink);}

};


#endif //CANADIANEXPERIENCE_ROTATIONALSOURCE_H
