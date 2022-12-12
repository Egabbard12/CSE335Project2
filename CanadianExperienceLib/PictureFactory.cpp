/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include <wx/stdpaths.h>
#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawableFactory.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();


    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    MachineDrawableFactory machineAdapterFactory;
    auto machineOne = machineAdapterFactory.Create(imagesDir,picture,1);
    machineOne->SetPosition(wxPoint(300,500));
    picture->AddActor(machineOne);

    auto machineTwo = machineAdapterFactory.Create(imagesDir, picture, 2);
    machineTwo->SetPosition(wxPoint(700,500));
    picture->AddActor(machineTwo);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 520));
    picture->AddActor(sparty);



    // Add prop
    auto flag = make_shared<Actor>(L"flag");
    flag->SetClickable(false);
    flag->SetPosition(wxPoint(0, 0));
    auto flagI =
            make_shared<ImageDrawable>(L"flag", imagesDir + L"/flag.png");
    flag->AddDrawable(flagI);
    flag->SetRoot(flagI);
    picture->AddActor(flag);

    return picture;
}

