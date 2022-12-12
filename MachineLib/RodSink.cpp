/**
 * @file RodSink.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "RodSink.h"
#include "Rod.h"

#include <utility>
#include "Component.h"
#include "Negotiator.h"
#include "Lever.h"
#include "Piston.h"
#include <cmath>
/**
 * Constructor
 * @param component Component we are connected to.
 */
RodSink::RodSink(Component *component)
{

}

/**
 * Negotiates rotation and position for rod
 * @param rod
 */
void RodSink::Negotiate(Rod *rod) {
    mNegotiator->Negotiate(rod);

}

