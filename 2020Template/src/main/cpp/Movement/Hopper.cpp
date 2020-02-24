#include "Movement/Hopper.hpp"
// AKA magazine and the intake 

Hopper::Hopper(
   rev::CANSparkMax &Belt,
   rev::CANSparkMaxLowLevel &Intake,
   FRC5572Controller &Operator,
   frc::DoubleSolenoid &IntakePistions,
   frc::DigitalInput &Input1,
   frc::DigitalInput &Input2,
   frc::DigitalInput &Photo
){
    this->belt = &Belt;
    this->intake = &Intake;
    this->Operator = &Operator;
    this->intakePistions = &IntakePistions;
    this->limitSwitch1 = &Input1;
    this->limitSwitch2 = &Input2;
    this->Photo = &Photo;
}

void Hopper::HopperPeriodic(){
   Hopper::ManualControl();
   Hopper::RunIntake();
   Hopper::Advance();
}

void Hopper::Advance(){
   if( !(Photo->Get()) ){
      if(Operator->X() && !(limitSwitch2->Get()) ){
         belt->Set(.3);
         }
      else {
         belt->Set(0.0);
         }
   }

   if(limitSwitch1->Get()){
      readyToLoad = true;
   }
   else {
      readyToLoad = false;
   }
}

void Hopper::ManualControl(){
   if(this->Operator->RB()){
      this->belt->Set(.3);
   }
   else{
      this->belt->Set(0.0);
   }
}

void Hopper::RunIntake(){
   if(Operator->X()){
      intake->Set(.9);
      intakePistions->Set(frc::DoubleSolenoid::Value::kReverse); // do toggle
   }
   else{
      intake->Set(0.0);
      intakePistions->Set(frc::DoubleSolenoid::Value::kForward);
   }
}