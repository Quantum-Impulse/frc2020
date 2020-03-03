#include "Movement/Shooter.hpp"

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

void Shooter::Shots(){

    if(this->Operator->POV() == 0 ){
        shooterMotors->Set(.65);
        Hood->Set(frc::DoubleSolenoid::Value::kReverse);    
    }
    else if(this->Operator->POV() == 90){
        shooterMotors->Set(.87);
        Hood->Set(frc::DoubleSolenoid::Value::kForward); 
    }
    else if(this->Operator->POV() == 270){
        shooterMotors->Set(.92); //small adjustment from .92 to .94
        Hood->Set(frc::DoubleSolenoid::Value::kForward); 
    }
    else{
        shooterMotors->Set(0.0);
        Hood->Set(frc::DoubleSolenoid::Value::kReverse); 
    }
    leftRPM = leftMotorEncoder->GetVelocity();
    rightRPM = rightMotorEncoder->GetVelocity();
    rpm = ((leftRPM + rightRPM) / 2);

    frc::SmartDashboard::PutNumber("RPM", rpm);
    frc::SmartDashboard::PutNumber("Left RPM", leftRPM);
    frc::SmartDashboard::PutNumber("Right RPM", rightRPM);
}
