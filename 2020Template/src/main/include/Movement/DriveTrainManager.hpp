#ifndef DRIVE_TRAIN_HPP
#define DRIVE_TRAIN_HPP

#include "Movement/ControllerManager.hpp"
#include <frc/SpeedControllerGroup.h>
#include "rev/CANSparkMax.h"
#include "AHRS.h"



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

class DriveTrain
{
public:

DriveTrain(
  rev::CANSparkMax &TopLeftMotor     ,
  rev::CANSparkMax &TopRightMotor    ,
  rev::CANSparkMax &MiddleLeft       ,
  rev::CANSparkMax &MiddleRight      ,
  rev::CANSparkMax &BottomLeftMotor  , 
  rev::CANSparkMax &BottomRightMotor ,
  FRC5572Controller &Driver          ,
  AHRS &ahrs
  );

~DriveTrain();
void Drive();
void LowerAmps();
void Aim();

private:
  frc::SpeedControllerGroup* LeftMotors;
  frc::SpeedControllerGroup* RightMotors;
  
  FRC5572Controller* Driver;

  rev::CANSparkMax* TopleftMotor;
  rev::CANSparkMax* TopRightMotor;

  rev::CANSparkMax* MiddleLeft;
  rev::CANSparkMax* MiddleRight;  
  
  rev::CANSparkMax* BottomLeftMotor; 
  rev::CANSparkMax* BottomRightMotor;

  AHRS* ahrs;
  };  
#endif