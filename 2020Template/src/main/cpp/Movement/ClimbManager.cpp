#include "Movement/ClimbManager.hpp"

#include <frc/DoubleSolenoid.h>
ClimbManager::ClimbManager(
    frc::VictorSP& LeftClimb,
    frc::VictorSP& RightClimb,
    FRC5572Controller& Driver,
    frc::DoubleSolenoid& ClimbPistons
){
    this->leftClimb = &LeftClimb;
    this->rightClimb = &RightClimb;
    this->driver = &Driver;
    this->climbPistons = &ClimbPistons;
    this->climbMotors = new frc::SpeedControllerGroup(LeftClimb, RightClimb);
    //this->leftClimb->SetInverted(true);
    //this->rightClimb->SetInverted(false);

}

void ClimbManager::ClimbPeriodic(){
    ClimbManager::Down();
    ClimbManager::Spin();
    ClimbManager::Up();
}

void ClimbManager::Up(){
    if(driver->LT() > 0){
        this->climbPistons->Set(frc::DoubleSolenoid::Value::kReverse); 
    }
    else{
        this->climbMotors->Set(frc::DoubleSolenoid::Value::kOff); // toogle
    }
    
}

void ClimbManager::Down(){
    if(driver->RT() > 0){ 
        this->climbPistons->Set(frc::DoubleSolenoid::Value::kForward); // combine down and spin
    }
    else{
        this->climbMotors->Set(frc::DoubleSolenoid::Value::kOff);
    }
}

void ClimbManager::Spin(){

    if(driver->B()){
        //this->leftClimb->Set(-0.3);
        //this->climbMotors->Set(-0.3);
        leftClimb->Set(.2);
        rightClimb->Set(.2);
    }
    else{
        //this->leftClimb->Set(0);
        //this->climbMotors->Set(0.0); / problem 
        leftClimb->Set(0);
        rightClimb->Set(0);
    }
    if(driver->LB()){
        leftClimb->Set(-0.2);
        rightClimb->Set(-0.2);
    }
    else{
        leftClimb->Set(0.0);
        rightClimb->Set(0.0);
    }
}
