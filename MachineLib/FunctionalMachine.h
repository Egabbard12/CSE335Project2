/**
 * @file FunctionalMachine.h
 * @author Eric Gabbard
 *
 * Holds the moving parts of the machine
 */

#ifndef CANADIANEXPERIENCE_FUNCTIONALMACHINE_H
#define CANADIANEXPERIENCE_FUNCTIONALMACHINE_H

class Component;
class Motor;

/**
 * This class holds the actual moving components
 * of the machine.
 */
class FunctionalMachine {
private:
    /// Point location for the functional machine
    wxPoint mPoint;
    /// Components owned by this machine
    std::vector<std::shared_ptr<Component>> mComponents;
    /// Motors that belong to this machine
    std::vector<std::shared_ptr<Motor>> mMotors;
public:
    /**
     * Constructor
     */
    FunctionalMachine()= default;;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    void SetLocation(wxPoint location);

    void SetMotorTime(double frame);

    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Adds a motor to the machine vector
     * @param motor motor for machine
     */
    void AddMotor(std::shared_ptr<Motor> motor) {mMotors.push_back(motor);};
};


#endif //CANADIANEXPERIENCE_FUNCTIONALMACHINE_H
