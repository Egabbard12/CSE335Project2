/**
 * @file TranslationSink.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "TranslationSink.h"
#include "Component.h"

/**
 * Constructor
 * @param component pointer to component this sink belongs to
 */
TranslationSink::TranslationSink(Component *component) : Sink(component)
{
}
