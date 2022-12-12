/**
 * @file MachineDrawableFactory.cpp
 * @author Eric Gabbard
 */

#include "pch.h"
#include "MachineDrawableFactory.h"
#include "Actor.h"
#include "MachineAdapter.h"
#include "Picture.h"

using namespace std;

/**
 * Creates an actor and adds machine from adapter to it.
 * Then adds to passed picture.
 *
 * @param imagesDir The image Directory
 * @param picture Picture you want to add the machine to
 * @param num The machine number you want to create.
 * @return std::shared_ptr<Actor> Actor the machine is a part of
 */
std::shared_ptr<Actor> MachineDrawableFactory::Create(std::wstring imagesDir,std::shared_ptr<Picture> picture,int num)
{
    if (num == 1) {
        shared_ptr<Actor> actor = make_shared<Actor>(L"MachineOne");

        std::shared_ptr<MachineAdapter> machineAdapter = std::make_shared<MachineAdapter>(L"MachineOne");
        machineAdapter->SetImagesDir(imagesDir);
        machineAdapter->Initialize();
        machineAdapter->SetMachineNumber(1);

        machineAdapter->Place(wxPoint(200, 300),0);
        machineAdapter->SetPosition(wxPoint(200,500));

        actor->SetRoot(machineAdapter);

        actor->AddDrawable(machineAdapter);
        picture->SetMachineAdapterLeft(machineAdapter);
        return actor;
    }
    else
    {
        shared_ptr<Actor> actor = make_shared<Actor>(L"MachineTwo");

        std::shared_ptr<MachineAdapter> machineAdapter = std::make_shared<MachineAdapter>(L"MachineTwo");
        machineAdapter->SetImagesDir(imagesDir);
        machineAdapter->Initialize();
        machineAdapter->SetMachineNumber(2);

        machineAdapter->Place(wxPoint(700,500),0);
        machineAdapter->SetPosition(wxPoint(700, 500));

        actor->SetRoot(machineAdapter);

        actor->AddDrawable(machineAdapter);
        picture->SetMachineAdapterRight(machineAdapter);
        return actor;
    }


}
