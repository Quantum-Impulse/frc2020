#ifndef DRIVE_TRAIN_HPP
#define DRIVE_TRAIN_HPP

#include <iostream>
#include "Movement/ControllerManager.hpp"
#include "rev/CANSparkMax.h"
#include "AHRS.h"

#include <frc/Drive/DifferentialDrive.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/DoubleSolenoid.h>

class DriveTrain
{
public:
DriveTrain(rev::CANSparkMax &TopLeftMotor ,
          rev::CANSparkMax &TopRightMotor, 
          rev::CANSparkMax &BottomLeftMotor, 
          rev::CANSparkMax &BottomRightMotor, 
          FRC5572Controller &Driver,
          AHRS &ahrs,
          frc::DoubleSolenoid &Left_Solenoid,
          frc::DoubleSolenoid &Right_Solenoid);

~DriveTrain();
void Drive();
void LowerAmps();
void POut();
void PRetract();

private:
  frc::MecanumDrive* MRobotDrive;
  frc::SpeedControllerGroup* LeftMotors;
  frc::SpeedControllerGroup* RightMotors;
  FRC5572Controller* Driver;
  frc::DoubleSolenoid* Left_Solenoid;
  frc::DoubleSolenoid* Right_Solenoid;
  rev::CANSparkMax* TopleftMotor;
  rev::CANSparkMax* TopRightMotor; 
  rev::CANSparkMax* BottomLeftMotor; 
  rev::CANSparkMax* BottomRightMotor;
  AHRS* ahrs;
  };  
#endif