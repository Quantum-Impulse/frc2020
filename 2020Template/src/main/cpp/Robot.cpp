#include <iostream>
#include <string>

#include "Robot.h"
#include "Movement/DriveTrainManager.hpp"

#include "rev/ColorSensorV3.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "cameraserver/CameraServer.h"

void Robot::RobotPeriodic()     
{ 
    driveTrain.Drive();
    
    Color.GetClosestColor();
    Color.OutputColor();
}

void Robot::RobotInit()          {}
void Robot::AutonomousInit()     {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit()         {}
void Robot::TeleopPeriodic()     {}
void Robot::TestPeriodic()       {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
