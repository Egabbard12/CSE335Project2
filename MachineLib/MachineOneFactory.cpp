/**
 * @file MachineOneFactory.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "MachineOneFactory.h"
#include "FunctionalMachine.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"
#include "Piston.h"
#include "Cylinder.h"

using namespace std;

/**
 * Create Machine #1
 * @param actualMachine Actual machine that called the factory
 * @param imageDir Image directory for machine
 * @return Newly created machine
 */
std::shared_ptr<FunctionalMachine> MachineOneFactory::Create(ActualMachine *actualMachine, std::wstring imageDir)
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
    motor->SetImage(imageDir + L"/motor-frame.png");
    motor->CenteredSquare(100);
    motor->SetPosition(100, -35 - 51);
    motor->SetMotorSpeed(1.0);
    motor->SetShaftImage(imageDir + L"/electric-wheel.png");
    machine->AddComponent(motor);
    machine->AddMotor(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear2 = make_shared<Gear>(40,20);
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(imageDir + L"/iron.png");

    gear1->SetPosition(100, -38 - 100 / 2);
    motor->GetSource()->AddSink(gear1->GetSink());
    machine->AddComponent(gear1);

    // A post that holds the larger gear
    auto gear2post = make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(gear1->GetPosition().x + 55, -40);
    gear2post->SetColor(wxColour(0, 128, 0));

    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    gear2->SetImage(imageDir + L"/hammered-copper.png");
    gear2->SetPosition(gear1->GetPosition().x + 55, gear1->GetPosition().y);
    gear1->Drive(gear2,0.1);
    machine->AddComponent(gear2);


    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-15, -40, 40, 220);
    column->SetImage(imageDir + L"/column.png");

    // The lever
    auto lever = make_shared<Lever>(400);
    lever->SetPosition(0, -232);
    lever->SetLocation(wxPoint(0,-232));
    lever->SetLeftEnd(wxPoint(-200,-232));
    lever->SetImage(imageDir + L"/lever.png");

    //lever->SetDriveEnd(185);
    machine->AddComponent(lever);


    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(50);
    arm->SetImage(imageDir + L"/arm1.png");
    arm->SetPosition(gear2->GetPosition().x,gear2->GetPosition().y);
    arm->SetRotationPoint(wxPoint(arm->GetPosition().x,arm->GetPosition().y));

    gear2->GetSource()->AddSink(arm->GetSink());
    machine->AddComponent(arm);

    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(imageDir + L"/flag.png");
    flag->SetPosition(lever->GetPosition().x,lever->GetPosition().y);
    machine->AddComponent(flag);
    lever->GetRotationSource()->AddSink(flag->GetSink());

    // Column is added after the lever so it is in front
    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(150);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);

    arm->GetSource()->SetComponent(&*rod1);
    rod1->SetHeight(7);
    rod1->SetPosition(arm->GetArmEnd().x, arm->GetArmEnd().y - (150/2));
    rod1->Rectangle(arm->GetArmEnd().x,arm->GetArmEnd().y,150,7);
    rod1->SetRodSink(lever->GetRodSink());
    rod1->SetEndRod(arm->GetArmEnd());
    rod1->SetConnectedArm(arm);

    arm->GetSource()->AddSink(rod1->GetTranslationSink());

    // Piston
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = make_shared<Piston>();
    double pistonH = 90;
    double pistonW = 0.386 * pistonH;
    double pistonC = (13.0 / 215.0 * pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(imageDir + L"/piston.png");
    piston->SetPosition(-175, -150);
    piston->SetHeight(pistonH);
    machine->AddComponent(piston);

    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(50, 5);
    rod2->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod2);


    rod2->SetLocation(wxPoint(lever->GetLength()/2,lever->GetPosition().y));
    rod2->SetPosition(-lever->GetLength()/2,lever->GetPosition().y);

    rod2->SetRodSink(piston->GetRodSink());
    rod2->SetEndRod(lever->GetLeftEnd());
    lever->GetTranslationSource()->AddSink(rod2->GetTranslationSink());
    piston->GetRodSink()->SetLever(&*lever);

    //Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(-175, -38);
    cylinder->SetImage(imageDir + L"/cylinder.png");
    machine->AddComponent(cylinder);

    actualMachine->SetMachineFrame(0);

    return machine;
}

/**
 * Constructor
 * @param imagesDir Directory for machine parts images
 */
MachineOneFactory::MachineOneFactory(std::wstring imagesDir)
{
}


