#pragma once

#include <string>

#include "Vision/ColorManager.h"
#include "Movement/ControllerManager.hpp"
#include "Movement/DriveTrainManager.hpp"

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
  ColorManager      Color; 

  AHRS ahrs{SPI::Port::kMXP};

  /* Motors */
  rev::CANSparkMax m_leftTopMotor{leftLeadDeviceID, 
    rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightTopMotor{rightLeadDeviceID, 
    rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftBottomMotor{leftFollowDeviceID, 
    rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightBottomMotor{rightFollowDeviceID, 
    rev::CANSparkMax::MotorType::kBrushless};

  /* Soleniods */
  frc::DoubleSolenoid Left_Solenoid{PCM1, Left_Solenoid1, Left_Solenoid2};
  frc::DoubleSolenoid Right_Solenoid{PCM1, Right_Solenoid1, Right_Solenoid2};

  /*instantiation of the compressor with its CAN ID*/ 
  Compressor compressor{0};

  /*DriveTrain Object  */
  DriveTrain driveTrain{ m_leftTopMotor, m_rightTopMotor, m_leftBottomMotor,  m_rightBottomMotor, Driver, ahrs, Left_Solenoid, Right_Solenoid};

  /* IDS */
  static const int 
  leftLeadDeviceID = 1, 
  leftFollowDeviceID = 2,
  rightLeadDeviceID = 3,
  rightFollowDeviceID = 4,

  PCM1 = 5,
  PCM2 = 6,

  /* Solenoid port numbers */
  Right_Solenoid1 = 1,
  Right_Solenoid2 = 6,
  Left_Solenoid1 = 0,
  Left_Solenoid2 = 7;

 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
};




