#include "Movement/Hopper.hpp"

// AKA magazine and the intake
//d pad toggle preset shots 

Hopper::Hopper(
   rev::CANSparkMax &Belt,
   rev::CANSparkMaxLowLevel &Intake,
   FRC5572Controller &Operator,
   frc::DoubleSolenoid &IntakePistions,
   frc::DigitalInput &Input2,
   frc::DigitalInput &Input3
){
    this->belt = &Belt;
    this->intake = &Intake;
    this->Operator = &Operator;
    this->intakePistions = &IntakePistions;
    this->limitSwitch2 = &Input2;
    this->limitSwitch3 = &Input3;
}

void Hopper::HopperPeriodic(){
   Hopper::ManualControlBelt();
   Hopper::RunIntakePistions();
   Hopper::Advance();
   Hopper::ManualIntakeMotors();
}

//limit switch is naturally true until ball hits the swtich then it is false.
void Hopper::Advance(){
   if( !(this->Operator->R().second > 0.2 || this->Operator->R().second < -0.2) ){
      
      if( !( limitSwitch3->Get() ) ){ 
         if(Operator->X() ){
            belt->Set(.2);
            }
      }
      if(limitSwitch3->Get()){
         this->belt->Set(0.0);
      }
 }
         
}
/*
If you can get the rpms like you did with the TestRPM object in the shooter class
then use the rpm to make an if statment, having it so that if rpm > 4000 per say
then you can run the belt. (Make sure you add 

rev::CANSparkMax &LeftMotor,
rev::CANSparkMax &RightMotor,
leftMotorEncoder = new rev::CANEncoder{LeftMotor};
rightMotorEncoder = new rev::CANEncoder{RightMotor};
)

if((leftMotorEncoder->GetVelocity())>4000){
   if(this->Operator->R().second > 0.2){
      this->belt->Set(-0.25);
   }
   if(this->Operator->R().second < -0.2){
      this->belt->Set(0.25);
   }
   if(this->Operator->R().second < 0.2 && this->Operator->R().second > -0.2) {
      this->belt->Set(0.0);
   }
}

-Jay C (Sorry I was bored, if you don't want me touching this just lmk and I'll stop)
*/

void Hopper::ManualControlBelt(){
   if(this->Operator->R().second > 0.2){
      this->belt->Set(-0.25);
   }
   if(this->Operator->R().second < -0.2){
      this->belt->Set(0.25);
   }
   if(this->Operator->R().second < 0.2 && this->Operator->R().second > -0.2) {
      this->belt->Set(0.0);
   }

}

void Hopper::RunIntakePistions(){
   if(Operator->RT() > 0){
      intakePistions->Set(frc::DoubleSolenoid::Value::kForward);
   }
   else{
      intakePistions->Set(frc::DoubleSolenoid::Value::kReverse);
   }
}

void Hopper::ManualIntakeMotors(){
   if(this->Operator->L().second > 0.2){
      this->intake->Set(-.7);
   }

   if(this->Operator->L().second < -0.2){
      this->intake->Set(.7);
   }
   
   if(this->Operator->L().second < 0.2 && this->Operator->L().second > -0.2) {
      this->intake->Set(0.0);
   }
}