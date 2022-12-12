/**
 * @file Shape.h
 * @author Eric Gabbard
 *
 * Shape for our machine class
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "RotationalSink.h"

/**
 * Derived from component represents the shapes for our
 * machine.
 */
class Shape : public Component{
private:
    /// The rotational sink to update rotation for this shape
    RotationalSink mSink = RotationalSink(0,0,this); ///< The rotation sink for this component
public:
    Shape();
    void UpdateComponent(double param) override;
    /**
     * Getter for the sink owned by this shape
     * @return Rotational Sink
     */
    RotationalSink *GetSink(){return &mSink;}

};


#endif //CANADIANEXPERIENCE_SHAPE_H
