/**
 * @file Component.h
 * @author Eric Gabbard
 *
 *  Base Component for the machine
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

class Rod;

/**
 * Used to derive machine parts from
 */
class Component : public Polygon{
private:
    /// Position of the component
    wxPoint mPosition;
    /// Location of the component relative to the screen
    wxPoint mLocation;
    /// Center of rotation for the component
    wxPoint mRotationPoint;
public:
    Component() = default;

    virtual void DrawComponent(std::shared_ptr<wxGraphicsContext> graphics,int x,int y);

    void SetLocation(wxPoint location);

    virtual void UpdateComponent(double param);
    /**
     * base virtual class to update components translation sinks
     * @param component
     */
    virtual void UpdateComponentTranslation(Component *component) {};

    void SetPosition(int x, int y);
    /**
     * Get the location relative to the screen
     * @return wxPoint location
     */
    wxPoint GetLocation(){return mLocation;}

    /**
     * sets the rotation point for the component
     * @param point
     */
    void SetRotationPoint(wxPoint point){mRotationPoint = point;}

    virtual void SetRotation(double rotation);

    /**
     * Get position for componente relative to machine center
     * @return wxPoint for the position
     */
    wxPoint GetPosition(){return mPosition;}
    /**
     * Get the point of rotation for the component
     * @return
     */
    wxPoint GetPointOfRotation(){return mRotationPoint;}
};


#endif //CANADIANEXPERIENCE_COMPONENT_H
