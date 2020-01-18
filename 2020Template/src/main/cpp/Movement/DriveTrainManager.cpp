#include <iostream>

#include "Movement/DriveTrainManager.hpp"
#include "Movement/ControllerManager.hpp"

#include "rev/CANSparkMax.h"
#include <frc/Drive/DifferentialDrive.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/DoubleSolenoid.h>

DriveTrain::DriveTrain(rev::CANSparkMax &TopLeftMotor ,
          rev::CANSparkMax &TopRightMotor, 
          rev::CANSparkMax &BottomLeftMotor, 
          rev::CANSparkMax &BottomRightMotor, 
          FRC5572Controller &Driver,
          AHRS &ahrs,
          frc::DoubleSolenoid &Left_Solenoid,
          frc::DoubleSolenoid &Right_Solenoid){
            this->LeftMotors = new frc::SpeedControllerGroup( TopLeftMotor, BottomLeftMotor);
            this->RightMotors = new frc::SpeedControllerGroup( TopRightMotor, BottomRightMotor);
            this-> MRobotDrive = new frc::MecanumDrive( TopLeftMotor, BottomLeftMotor, TopRightMotor, BottomRightMotor);
            this->Driver = &Driver;
            this->ahrs = &ahrs; 
            this->Left_Solenoid = &Left_Solenoid;
            this->Right_Solenoid = &Right_Solenoid;
            this->TopleftMotor = &TopLeftMotor;
            this->TopRightMotor = &TopRightMotor;
            this->BottomLeftMotor = &BottomLeftMotor;
            this->BottomRightMotor = &BottomRightMotor;
}

DriveTrain::~DriveTrain()
{
    delete LeftMotors, RightMotors, Driver, ahrs, 
        MRobotDrive, Left_Solenoid, Right_Solenoid ;
}

void DriveTrain::Drive()
{
    LowerAmps();
    if(Driver->toggleA)
    {
        PRetract();
        LeftMotors->Set(Driver->L().second);
        RightMotors->Set(Driver->R().second);
    }
    else{
        POut();
        MRobotDrive->DriveCartesian(Driver->L().second, Driver->L().first, Driver->R().first, ahrs->GetYaw());
    }
}

void DriveTrain::LowerAmps(){
    TopleftMotor->SetSmartCurrentLimit(40);
    TopRightMotor->SetSmartCurrentLimit(40);
    BottomLeftMotor->SetSmartCurrentLimit(40);
    BottomRightMotor->SetSmartCurrentLimit(40);
}

void DriveTrain::POut(){
    Left_Solenoid->Set(frc::DoubleSolenoid::Value::kForward);
    Right_Solenoid->Set(frc::DoubleSolenoid::Value::kForward);
}

void DriveTrain::PRetract(){
    Left_Solenoid->Set(frc::DoubleSolenoid::Value::kReverse);
    Right_Solenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}
