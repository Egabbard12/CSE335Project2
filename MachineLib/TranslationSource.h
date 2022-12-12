/**
 * @file TranslationSource.h
 * @author Eric Gabbard
 *
 * Source for changing child positions
 */

#ifndef CANADIANEXPERIENCE_TRANSLATIONSOURCE_H
#define CANADIANEXPERIENCE_TRANSLATIONSOURCE_H

#include "TranslationSink.h"
#include "RectangularComponent.h"
class Rod;
/**
 * Source to update translational sinks
 */
class TranslationSource {
private:
    /// Speed for this source to pass to sinks
    double mSpeed;
    /// Vector of sinks to update
    std::vector<TranslationSink *> mSinks;
    /// Component ths sink belongs to
    Component *mComponent;
public:
    TranslationSource() = default;
    /// Copy constructor (disabled)
    TranslationSource(const TranslationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const TranslationSource &) = delete;

    void UpdateSinks(Component *component);
    /**
     * Adds a sink to this source
     * @param sink TranslationSink
     */
    void AddSink(TranslationSink *sink){mSinks.push_back(sink);}
    /**
     * Set Parent Component
     * @param component
     */
    void SetComponent(Component *component){mComponent = component;}
    /**
     * Get Component this source belongs to
     * @return
     */
    Component *GetComponent(){return mComponent;}
};


#endif //CANADIANEXPERIENCE_TRANSLATIONSOURCE_H
