#include <iostream>
#include <string>

#include "Robot.h"
#include "Movement/DriveTrainManager.hpp"

#include "rev/ColorSensorV3.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "cameraserver/CameraServer.h"

#include <frc/Timer.h>

void Robot::RobotInit(){

    // m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    // m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    //frc::SmartDashboard::PutData( "a", actualRPM );
}

void Robot::RobotPeriodic(){ 
    LimeLight.Update();

    driveTrain.Drive();

    //shooter.Shot();

    //shooter.TestRPM();

    shooter.Shots();

    //shooter.Test();
    
    climber.ClimbPeriodic();

    hopper.HopperPeriodic();

    // std::cout << "Velocity X: " << ahrs.GetVelocityX << std::endl;
    // std::cout << "Velocity Y: " << ahrs.GetVelocityY << std::endl;
    // std::cout << "Velocity Z: " << ahrs.GetVelocityZ << std::endl;
    // std::cout << "Acceleration X" << ahrs.GetWorldLinearAccelX() << std::endl;
    // std::cout << "Acceleration Y" << ahrs.GetWorldLinearAccelY() << std::endl;
    // std::cout << "Acceleration Z" << ahrs.GetWorldLinearAccelZ() << std::endl;

}

void Robot::AutonomousInit()     {
    autoDrip.ResetTimer();
}

void Robot::AutonomousPeriodic() { 
    autoDrip.BumperShot();
}

void Robot::TeleopInit()         {

}

void Robot::TeleopPeriodic()     {

}

void Robot::TestInit()  {
    
}

void Robot::TestPeriodic()       {
    
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
