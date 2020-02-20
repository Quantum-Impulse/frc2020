#pragma once

#include <string>

#include "Vision/ColorManager.h"
#include "Movement/ControllerManager.hpp"
#include "Movement/DriveTrainManager.hpp"
#include "AHRS.h"

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/util/color.h>

#include "rev/CANSparkMax.h"
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>

class Robot : public frc::TimedRobot
{
 private:
  FRC5572Controller Driver{0}; 
  FRC5572Controller Operator{1};

  AHRS ahrs{SPI::Port::kMXP};

  /* DriveTrain Spark Max and Motors*/
  rev::CANSparkMax m_leftTopMotor{TopLeft, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightTopMotor{TopRight, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_leftMiddleMotor{MiddleLeft, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightMiddleMotor{RightMid, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_leftBottomMotor{LeftMid, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightBottomMotor{RightMid, 
    rev::CANSparkMax::MotorType::kBrushless};
 
 /* Shooters Spark Max and Motors*/
  rev::CANSparkMax m_leftShooter{leftShoot, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightShooter{rightShoot, 
    rev::CANSparkMax::MotorType::kBrushless};
 
 /* Intake */
  rev::CANSparkMax m_intake{intake, 
    rev::CANSparkMax::MotorType::kBrushless};

/* Hopper */
  rev::CANSparkMax m_hopper{hopper, 
    rev::CANSparkMax::MotorType::kBrushless};

/* Climber */
  rev::CANSparkMax m_LeftClimb{LeftClimb, 
    rev::CANSparkMax::MotorType::kBrushed};

  rev::CANSparkMax m_RightClimb{RightClimb, 
    rev::CANSparkMax::MotorType::kBrushed};

  /*instantiation of the compressor with its CAN ID*/ 
  Compressor compressor{0};

  frc::DoubleSolenoid climb{1, 0, 0};

  frc::DoubleSolenoid shooterHood{1, 0, 0}; 

  /*DriveTrain Object  */
  DriveTrain driveTrain{ m_leftTopMotor, m_rightTopMotor, m_leftMiddleMotor, m_rightMiddleMotor, m_leftBottomMotor, m_rightBottomMotor, Driver, ahrs};

  /* IDS */
  static const int
  //Drive Train IDs 
  TopLeft = 1,
  TopRight = 2,
  
  MiddleLeft = 3,
  MiddleRight = 4,

  LeftMid = 5,
  RightMid = 6,
  
  //Shooter Ids
  leftShoot = 7,
  rightShoot = 8,

  //intake IDs
  intake = 9,
  
  //hopper 
  hopper = 10,
  
  //PCM IDs
  PCM1 = 11,
  PCM2 = 12,
  
  //Climber IDs
  LeftClimb = 13,
  RightClimb = 14;

 public:
  void RobotInit() override;

  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
};




