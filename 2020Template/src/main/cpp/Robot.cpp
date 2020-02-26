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

    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

void Robot::RobotPeriodic(){ 
    LimeLight.Update();

    driveTrain.Drive();

    shooter.Shot();
    
    climber.ClimbPeriodic();

    hopper.HopperPeriodic();
}

void Robot::AutonomousInit()     {


}

void Robot::AutonomousPeriodic() {

    double time = Timer::getFPGATimestamp();
    cout << time - startTime << endl;
    if (time - startTime < 3) {
        
    }
}

void Robot::TeleopInit()         {

}

void Robot::TeleopPeriodic()     {

}

void Robot::TestInit()  {

}

void Robot::TestPeriodic()       {
    photoSensor.teachSensor();
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
