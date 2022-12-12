/**
 * @file MachineDrawableFactory.h
 * @author Eric Gabbard
 *
 * Creates the MachineAdapter class to create the machines
 */



class Actor;
class Picture;
#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H

/**
 * Factory for creating the machines through the adapter class
 */
class MachineDrawableFactory {
private:
public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir,std::shared_ptr<Picture> picture, int num);
};


#endif //CANADIANEXPERIENCE_MACHINEDRAWABLEFACTORY_H
