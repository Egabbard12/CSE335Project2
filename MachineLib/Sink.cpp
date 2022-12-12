/**
 * @file Sink.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "Sink.h"

/**
 * Update The component position
 * @param component
 */
void Sink::UpdateComponentTranslation(Component *component) {
    mComponent->UpdateComponentTranslation(component);
}