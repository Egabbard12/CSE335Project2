/**
 * @file MachineOneFactory.h
 * @author Eric Gabbard
 *
 * Factory for creating Machine 1
 */

#ifndef CANADIANEXPERIENCE_MACHINEONEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEONEFACTORY_H

#include "MachineFactory.h"
#include "FunctionalMachine.h"

class ActualMachine;

/**
 * Creates a functioning machine for machine1
 */
class MachineOneFactory{
private:

public:
    /// Delete default constructor
    MachineOneFactory() = delete;
    /// Copy constructor (disabled)
    MachineOneFactory(const MachineOneFactory &) = delete;
    /// Assignment operator
    void operator=(const MachineOneFactory &) = delete;

    explicit MachineOneFactory(std::wstring imagesDir);

    std::shared_ptr<FunctionalMachine> Create(ActualMachine *actualMachine, std::wstring imageDir);
};


#endif //CANADIANEXPERIENCE_MACHINEONEFACTORY_H
