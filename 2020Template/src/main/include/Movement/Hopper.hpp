#ifndef HOPPER_HPP
#define HOPPER_HPP

#include "rev/CANSparkMax.h"
#include "Movement/ControllerManager.hpp"
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>

// AKA magazine and the intake 

class Hopper{
    public:

    Hopper(
        rev::CANSparkMax &Belt,
        rev::CANSparkMaxLowLevel &Intake,
        FRC5572Controller &Operator,
        frc::DoubleSolenoid &IntakePistions,
        frc::DigitalInput &Input2,
        frc::DigitalInput &Input3
    );

    void HopperPeriodic();
    void Advance();
    void ManualControlBelt();
    void RunIntakePistions();
    void ManualIntakeMotors();

    bool readyToLoad = false ;
    FRC5572Controller* Operator;
    rev::CANSparkMax* belt;
    rev::CANSparkMaxLowLevel* intake;
    frc::DoubleSolenoid* intakePistions;
    frc::DigitalInput* limitSwitch2;
    frc::DigitalInput* limitSwitch3;

};

#endif