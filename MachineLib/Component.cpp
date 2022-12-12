/**
 * @file Component.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Component.h"

/**
 * Calls DrawPolygon for component passing the relative position
 * @param graphics graphics for machine
 * @param x machine x coordinate
 * @param y machine y coordinate
 */
void Component::DrawComponent(std::shared_ptr<wxGraphicsContext> graphics,int x,int y)
{
    DrawPolygon(graphics, x+mPosition.x, y+mPosition.y);
}

/**
 * Updates components
 * @param param double to update component with
 */
void Component::UpdateComponent(double param)
{

}

/**
 * Set rotation for component
 *
 * Calls Polygon::SetRotation
 * @param rotation
 */
void Component::SetRotation(double rotation) {
    Polygon::SetRotation(rotation);
}

/**
 * Set component position relative to center
 * @param x x coordinate to set for component
 * @param y y coordinate to set for component
 */
void Component::SetPosition(int x, int y) {
    mPosition = wxPoint(x,y);
}

/**
 * Set location relative to screen
 * @param location location on screen
 */
void Component::SetLocation(wxPoint location) {
    mLocation = location;
}
