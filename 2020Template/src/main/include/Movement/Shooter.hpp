#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include "rev/CANSparkMax.h"
#include "AHRS.h"
#include "Movement/ControllerManager.hpp"
#include <frc/SpeedControllerGroup.h>

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

class Shooter{
    public:

    Shooter(
        rev::CANSparkMax &LeftMotor,
        rev::CANSparkMax &RightMotor,
        FRC5572Controller &Operator,
        double &Distance,
        bool &Tracked
    );

    void Shot();
    void Calucate();
    
    bool Tracked = false, hood = false;
    double Power = 0, Distance = 0;

    frc::SpeedControllerGroup* shooterMotors;
    
    FRC5572Controller* Operator;

    rev::CANSparkMax* leftMotor;
    rev::CANSparkMax* rightMotor;
};

#endif