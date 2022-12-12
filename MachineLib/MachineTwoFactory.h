/**
 * @file MachineTwoFactory.h
 * @author Eric Gabbard
 *
 * Factory to make machine 2
 */

#ifndef CANADIANEXPERIENCE_MACHINETWOFACTORY_H
#define CANADIANEXPERIENCE_MACHINETWOFACTORY_H

#include "MachineFactory.h"
#include "FunctionalMachine.h"

class ActualMachine;
/**
 * Factory to make machine 2
 */
class MachineTwoFactory{
private:

public:
    /// Delete default constructor
    MachineTwoFactory() = delete;
    /// Copy constructor (disabled)
    MachineTwoFactory(const MachineTwoFactory &) = delete;
    /// Assignment operator
    void operator=(const MachineTwoFactory &) = delete;

    explicit MachineTwoFactory(std::wstring imagesDir);
    std::shared_ptr<FunctionalMachine> Create(ActualMachine *actualMachine, std::wstring imageDir);
};


#endif //CANADIANEXPERIENCE_MACHINETWOFACTORY_H
