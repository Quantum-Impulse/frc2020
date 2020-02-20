#include "Movement/DriveTrainManager.hpp"

/* CAN ID layout for drive train from a top view

          Front of Robot
         
         |--------------|
         |              |
      1  | M1        M2 | 2
      3  | M3        M4 | 3
      5  | M5        M6 | 6
         |              |
         |              |
         |--------------|

          Back Of Robot
*/

DriveTrain::DriveTrain(
    rev::CANSparkMax &TopLeftMotor,
    rev::CANSparkMax &TopRightMotor,

    rev::CANSparkMax &MiddleLeft,
    rev::CANSparkMax &MiddleRight,

    rev::CANSparkMax &BottomLeftMotor, 
    rev::CANSparkMax &BottomRightMotor,

    FRC5572Controller &Driver,
    AHRS &ahrs
    ){
        this->LeftMotors = new frc::SpeedControllerGroup( TopLeftMotor, MiddleLeft, BottomLeftMotor);
        this->RightMotors = new frc::SpeedControllerGroup( TopRightMotor, MiddleRight, BottomRightMotor);
        
        this->Driver = &Driver;
        this->ahrs = &ahrs;

        this->TopleftMotor = &TopLeftMotor;
        this->TopRightMotor = &TopRightMotor;

        this->MiddleLeft = &MiddleLeft;
        this->MiddleRight = &MiddleRight;

        this->BottomLeftMotor = &BottomLeftMotor;
        this->BottomRightMotor = &BottomRightMotor;

        this->TopleftMotor->SetInverted(true);
}

DriveTrain::~DriveTrain()
{
    delete LeftMotors, RightMotors, Driver, ahrs ;
}

void DriveTrain::Drive()
{
    LeftMotors->Set(Driver->L().second);
    RightMotors->Set(Driver->R().second);
}

void DriveTrain::LowerAmps(){
    TopleftMotor->SetSmartCurrentLimit(40);
    TopRightMotor->SetSmartCurrentLimit(40);
    BottomLeftMotor->SetSmartCurrentLimit(40);
    BottomRightMotor->SetSmartCurrentLimit(40);
}

void DriveTrain::Aim(){
    
}
