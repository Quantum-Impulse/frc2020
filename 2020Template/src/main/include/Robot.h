#pragma once

#include <string>

#include "Vision/ColorManager.h"
#include "Movement/ControllerManager.hpp"
#include "Movement/DriveTrainManager.hpp"
#include "Movement/Shooter.hpp"
#include "AHRS.h"

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/util/color.h>
#include <frc/DigitalInput.h>

#include "rev/CANSparkMax.h"
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>

class Robot : public frc::TimedRobot
{
 private:
 
 // Controllers
  FRC5572Controller Driver{0}; 
  FRC5572Controller Operator{1};

  //Nav-XMP board
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
  rev::CANSparkMax m_leftShooter{LeftShoot, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightShooter{RightShoot, 
    rev::CANSparkMax::MotorType::kBrushless};
 
 /* Intake */
  rev::CANSparkMax m_intake{Intake, 
    rev::CANSparkMax::MotorType::kBrushless};

/* Hopper */
  rev::CANSparkMax m_hopper{hopper, 
    rev::CANSparkMax::MotorType::kBrushless};

/* Climber */
  rev::CANSparkMax m_LeftClimb{LeftClimb, 
    rev::CANSparkMax::MotorType::kBrushed};

  rev::CANSparkMax m_RightClimb{RightClimb, 
    rev::CANSparkMax::MotorType::kBrushed};

  /*instantiation of the compressor with its CAN ID and pneumatics*/ 
  Compressor compressor{0};

  frc::DoubleSolenoid climb{PCM1, 0, 0};

  frc::DoubleSolenoid shooterHood{PCM1, 0, 0};

  frc::DoubleSolenoid intake{PCM1 ,0 ,0};  

  // Sensor
  frc::DigitalInput limitSwitch1{0};
  frc::DigitalInput limitSwitch2{1};

  /*DriveTrain Object  */
  DriveTrain driveTrain{ m_leftTopMotor, m_rightTopMotor, m_leftMiddleMotor, m_rightMiddleMotor, m_leftBottomMotor, m_rightBottomMotor, Driver, ahrs};

  Shooter shooter{m_leftShooter, m_rightShooter, shooterHood, Operator};
  
  

  /* IDS */
  static const int
  TopLeft = 1,
  TopRight = 2,
  
  MiddleLeft = 3,
  MiddleRight = 4,

  LeftMid = 5,
  RightMid = 6,

  LeftShoot = 7,
  RightShoot = 8,

  Intake = 9,
  
  PCM1 = 10,

  hopper = 11,
  
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




