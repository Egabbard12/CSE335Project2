/**
 * @file TranslationSink.h
 * @author Eric Gabbard
 *
 * Sink for updating position of components
 */

#ifndef CANADIANEXPERIENCE_TRANSLATIONSINK_H
#define CANADIANEXPERIENCE_TRANSLATIONSINK_H

#include "Sink.h"

class Component;
class Rod;

/**
 * Updates position of components
 */
class TranslationSink : public Sink{
private:

public:
    /// Delete default constructor
    TranslationSink() = delete;
    /// Delete copy constructor
    TranslationSink(const TranslationSink &) = delete;
    /// Delete assignment operator
    void operator=(const TranslationSink &) = delete;
    explicit TranslationSink(Component *component);
};


#endif //CANADIANEXPERIENCE_TRANSLATIONSINK_H
