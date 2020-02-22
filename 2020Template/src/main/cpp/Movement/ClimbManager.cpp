#include "Movement/ClimbManager.hpp"

#include <frc/DoubleSolenoid.h>
ClimbManager::ClimbManager(
    rev::CANSparkMax& LeftClimb,
    rev::CANSparkMax& RightClimb,
    FRC5572Controller& Driver,
    frc::DoubleSolenoid& ClimbPistons
){
    this->leftClimb = &LeftClimb;
    this->rightClimb - &RightClimb;
    this->driver = &Driver;
    this->climbPistons = &ClimbPistons;
    this->climbMotors = new frc::SpeedControllerGroup(LeftClimb, RightClimb);
    //this->leftClimb->SetInverted(true);
    //this->rightClimb->SetInverted(true);

}

void ClimbManager::Up(){
    if(driver->LT() > 0){
        this->climbPistons->Set(frc::DoubleSolenoid::Value::kForward);
    }
    else{
        this->climbMotors->Set(frc::DoubleSolenoid::Value::kOff);
    }
    
}

void ClimbManager::Down(){
    if(driver->RT() > 0){
        this->climbPistons->Set(frc::DoubleSolenoid::Value::kReverse);
    }
    else{
        this->climbMotors->Set(frc::DoubleSolenoid::Value::kOff);
    }
}

void ClimbManager::Spin(){
    if(driver->RT() > 0){
        this->climbMotors->Set(-0.3);
    }
    else{
        this->climbMotors->Set(0.0);
    }
}
