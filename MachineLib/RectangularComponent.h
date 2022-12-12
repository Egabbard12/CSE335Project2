/**
 * @file RectangularComponent.h
 * @author Eric Gabbard
 *
 * Rectangular component to
 * base components on.
 */

#ifndef CANADIANEXPERIENCE_RECTANGULARCOMPONENT_H
#define CANADIANEXPERIENCE_RECTANGULARCOMPONENT_H

#include "Component.h"

/**
 * Rectangular component to base components on.
 */
class RectangularComponent : public Component{
private:
    /// Length of component
    double mLength;
    /// Height of component
    double mHeight;
public:
    /**
     * Constructor
     */
    RectangularComponent() = default;
    /**
     * Set Length of component
     * @param length
     */
    void SetLength(double length){mLength = length;}
    /**
     * Set Height of component
     * @param height
     */
    void SetHeight(double height){mHeight = height;}
    /**
     * Getter for length of component
     * @return double
     */
    double GetLength() const{return mLength;}
    /**
     * Getter for height of component
     * @return double
     */
    double GetHeight() const{return mHeight;}

};


#endif //CANADIANEXPERIENCE_RECTANGULARCOMPONENT_H
