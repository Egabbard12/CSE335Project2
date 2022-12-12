project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h MachineOneFactory.cpp MachineOneFactory.h ActualMachine.cpp ActualMachine.h FunctionalMachine.cpp FunctionalMachine.h Component.cpp Component.h Shape.cpp Shape.h Motor.cpp Motor.h RotationalSource.cpp RotationalSource.h MachineTwoFactory.cpp MachineTwoFactory.h RotationalSink.cpp RotationalSink.h Gear.cpp Gear.h Arm.cpp Arm.h Rod.cpp Rod.h TranslationSink.cpp TranslationSink.h TranslationSource.cpp TranslationSource.h Negotiator.cpp Negotiator.h RodSink.cpp RodSink.h RectangularComponent.cpp RectangularComponent.h Lever.cpp Lever.h Sink.cpp Sink.h Piston.cpp Piston.h Cylinder.cpp Cylinder.h Polygon.h Polygon.cpp)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)