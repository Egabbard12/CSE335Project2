/**
 * @file MachineTwoFactory.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "MachineTwoFactory.h"
#include "FunctionalMachine.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"


using namespace std;


/**
 * Constructor
 *
 * @param imagesDir Image directory for machine parts
 */
MachineTwoFactory::MachineTwoFactory(std::wstring imagesDir)
{
}

/**
 * Creates the second machine factory
 *
 * @param actualMachine Actual machine for this factory
 * @param imageDir Image directory for machine parts
 * @return FunctionalMachine
 */
std::shared_ptr<FunctionalMachine> MachineTwoFactory::Create(ActualMachine *actualMachine, std::wstring imageDir)
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<FunctionalMachine>();

    // The base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(imageDir + L"/base.png");
    machine->AddComponent(base);

    // The motor
    auto motor = make_shared<Motor>(actualMachine);
    motor->SetImage(imageDir + L"/motor2.png");
    motor->CenteredSquare(100);
    motor->SetPosition(-100, -35 - 51);
    motor->SetMotorSpeed(1.0);
    motor->SetShaftImage(imageDir + L"/shaft.png");
    motor->SetShaftFront();
    machine->AddComponent(motor);
    machine->AddMotor(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear2 = make_shared<Gear>(40,20);
    auto gear1 = make_shared<Gear>(40, 20);
    gear1->SetImage(imageDir + L"/iron.png");

    gear1->SetPosition(-100, -35-51);
    motor->GetSource()->AddSink(gear1->GetSink());
    machine->AddComponent(gear1);


    // A post that holds the larger gear
    auto gear2post = make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(gear1->GetPosition().x + 75, -40);
    gear2post->SetColor(wxColour(0, 128, 0));

    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    gear2->SetImage(imageDir + L"/hammered-copper.png");
    gear2->SetPosition(gear1->GetPosition().x + 75, gear1->GetPosition().y);
    gear1->Drive(gear2,0.1);
    machine->AddComponent(gear2);

    // A post that holds the larger gear
    auto gear3post = make_shared<Shape>();
    gear3post->Rectangle(-10, 0, 20, 130);
    gear3post->SetPosition(gear2->GetPosition().x + 75, -40);
    gear3post->SetColor(wxColour(0, 128, 0));

    machine->AddComponent(gear3post);

    auto gear3 = make_shared<Gear>(80, 40);
    gear3->SetImage(imageDir + L"/iron.png");

    gear3->SetPosition(gear2->GetPosition().x + 75, -170);
    gear2->Drive(gear3,0.1);

    machine->AddComponent(gear3);

    // A post that holds the larger gear
    auto gear4post = make_shared<Shape>();
    gear4post->Rectangle(-10, 0, 20, 170);
    gear4post->SetPosition(gear3->GetPosition().x + 110, -40);
    gear4post->SetColor(wxColour(0, 128, 0));

    machine->AddComponent(gear4post);

    auto gear4 = make_shared<Gear>(40, 20);
    gear4->SetImage(imageDir + L"/hammered-copper.png");

    gear4->SetPosition(gear3->GetPosition().x + 103, -216);
    gear3->Drive(gear4,0.3);

    machine->AddComponent(gear4);

    auto flag = make_shared<Shape>();
    flag->SetImage(imageDir + L"/msu-flag.png");
    flag->Rectangle(0,1,30,80);
    flag->SetPosition(gear4->GetPosition().x,gear4->GetPosition().y);
    flag->SetRotationPoint(gear4->GetPosition());
    gear4->GetSource()->AddSink(flag->GetSink());
    flag->SetRotation(-30);

    machine->AddComponent(flag);

    actualMachine->SetMachineFrame(0);

    return machine;
}
