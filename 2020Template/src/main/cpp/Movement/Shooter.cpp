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
    FRC5572Controller &Operator,
    double &Distance,
    bool &Tracked){

    shooterMotors = new frc::SpeedControllerGroup{ LeftMotor, RightMotor};
    this->Operator = &Operator;
    this->Distance = Distance;
    this->Tracked = Tracked;
}

void Shooter::Shot(){
    if(Tracked)
    {
        shooterMotors->Set(Power);
    }
    else
    {
        shooterMotors->Set(0); 
    }
}

void Shooter::Calucate(){
    
}