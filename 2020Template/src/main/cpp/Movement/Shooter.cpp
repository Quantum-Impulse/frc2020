#include "Movement/Shooter.hpp"


/* CAN ID layout for drive train from a top view

          Front of Robot
         
         |--------------|
         |              |
      ?  |    M?   M?   | ?
         |              | 
         |              | 
         |              |
         |              |
         |--------------|

          Back Of Robot
*/

Shooter::Shooter(
    rev::CANSparkMax &LeftMotor,
    rev::CANSparkMax &RightMotor,
    frc::DoubleSolenoid &Hood,
    FRC5572Controller &Operator
    ){
    this->leftMotor = &LeftMotor;
    this->rightMotor = &RightMotor;
    this->Hood = &Hood;
    this->Operator = &Operator;
    //this->leftMotor->SetInverted(true);
    //this->rightMotor->SetInverted(true);
    shooterMotors = new frc::SpeedControllerGroup{ LeftMotor, RightMotor};
    leftMotorEncoder = new rev::CANEncoder{LeftMotor};
    rightMotorEncoder = new rev::CANEncoder{RightMotor};

}

void Shooter::Shot(){
    if(Operator->B()){
        Hood->Set(frc::DoubleSolenoid::Value::kForward); //do toggle
    }
    else{
      Hood->Set(frc::DoubleSolenoid::Value::kReverse);  
    }

    if(Tracked)
    {
        shooterMotors->Set(Operator->RT());
    }
    else
    {
        shooterMotors->Set(0); 
    }
}

void Shooter::Calucate(){
    
}

void Shooter::Test(){
    if(Operator->LB()){
        //Hood->Set(frc::DoubleSolenoid::Value::kForward); 
        shooterMotors->Set(.65); 
    }
    else{
        shooterMotors->Set(0);
        //Hood->Set(frc::DoubleSolenoid::Value::kReverse); 
    }
}

void Shooter::TestRPM(){
    rpm = leftMotorEncoder->GetVelocity();
    std::cout << "RPM is: " << leftMotorEncoder->GetVelocity() << std::endl;
    
}

void Shooter::BumberShot(){
    /*
    if(Operator->BLaBla){
        shooterMotors->Set(1.0);
    }
    */
}
/*
void Shooter::InitShot
*/