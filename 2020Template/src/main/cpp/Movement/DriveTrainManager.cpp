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
    VisionManager &VisionManager,
    AHRS &ahrs
    ){
        this->LeftMotors = new frc::SpeedControllerGroup( TopLeftMotor, MiddleLeft, BottomLeftMotor);
        this->RightMotors = new frc::SpeedControllerGroup( TopRightMotor, MiddleRight, BottomRightMotor);
        this->TempRightMotors = new frc::SpeedControllerGroup( MiddleRight, BottomRightMotor);
        this->TempLeftMotors = new frc::SpeedControllerGroup( MiddleLeft, BottomLeftMotor);

        
        this->Driver = &Driver;
        this->ahrs = &ahrs;

        this->TopLeftMotor = &TopLeftMotor;
        this->TopRightMotor = &TopRightMotor;

        this->MiddleLeft = &MiddleLeft;
        this->MiddleRight = &MiddleRight;

        this->BottomLeftMotor = &BottomLeftMotor;
        this->BottomRightMotor = &BottomRightMotor;

        this->TopLeftMotorEncoder = new rev::CANEncoder{TopLeftMotor};
        this->TopRightMotorEncoder = new rev::CANEncoder{TopRightMotor};

        this->MiddleLeftMotorEncoder = new rev::CANEncoder{MiddleLeft};
        this->MiddleRightMotorEncoder = new rev::CANEncoder{MiddleRight};
        
        this->BottomLeftMotorEncoder = new rev::CANEncoder{BottomLeftMotor};
        this->BottomRightMotorEncoder = new rev::CANEncoder{BottomRightMotor};

        this->LimeLight = &VisionManager;

        DriveTrain::LowerAmps();
}

DriveTrain::~DriveTrain()
{
    delete LeftMotors;
    delete RightMotors;
    delete Driver;
    delete ahrs;
}

//#define QUAD(x) (log2(x + 1) - 1)

// void DriveTrain::Drive()
// {
//     if(this->Driver->L().second > .2 || this->Driver->L().second < -.2){
        
//         LeftMotors->Set(-1 * QUAD(Driver->L().second) * .8  );
//     }
//     else{
//         LeftMotors->Set(0 + L);
//     }

//     if(this->Driver->R().second > .2 ||  this->Driver->R().second < -.2){
//         RightMotors->Set(QUAD(Driver->R().second)  * .8);
//     }
//     else{
//         RightMotors->Set(0 + R);
//     }
// }

void DriveTrain::Drive()
{
    if(this->Driver->L().second > .2 || this->Driver->L().second < -.2){
        LeftMotors->Set(-1 * Driver->L().second * .7  );
    }
    else{
        LeftMotors->Set(0 + L);
    }

    if(this->Driver->R().second > .2 ||  this->Driver->R().second < -.2){
        RightMotors->Set(Driver->R().second  * .7);
    }
    else{
        RightMotors->Set(0 + R);
    }
}

void DriveTrain::LowerAmps(){
    TopLeftMotor->SetSmartCurrentLimit(60);
    TopRightMotor->SetSmartCurrentLimit(60);

    MiddleLeft->SetSmartCurrentLimit(60);
    MiddleRight->SetSmartCurrentLimit(60);

    BottomLeftMotor->SetSmartCurrentLimit(60);
    BottomRightMotor->SetSmartCurrentLimit(60);
}

void DriveTrain::Aim(){
    if (Driver->Y() ==  true)
    {
        disX = LimeLight->disX; 
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("camMode", 0);
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 3);
    }
    else if (Driver->Y() == false){
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("camMode", 1);
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 1);
        disX = 0;
        L = 0; R = 0;
    }
        
    if (fabs(disX) > 1 && Driver->X() == true)
        {
            if (disX > 10)
            {
                R = -.3;  
                L = -.3;
            }
            if (disX < 10)
            {
                R = -disX/35; 
                L = -disX/35;
            } 
            if (disX < -10)
            {
                R = .3;
                L = .3;
            }
            if (disX > -10)
            {
                R = disX/35; 
                L = disX/35;
            }
        }
    else{
        L = 0;
        R = 0;
        }
    

}
