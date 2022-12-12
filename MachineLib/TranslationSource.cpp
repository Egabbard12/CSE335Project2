/**
 * @file TranslationSource.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "TranslationSource.h"
#include "Component.h"

/**
 * Updates all children sinks positions
 * @param component
 */
void TranslationSource::UpdateSinks(Component *component)
{
    for (auto sink : mSinks)
    {
        sink->UpdateComponentTranslation(component);

    }
}
