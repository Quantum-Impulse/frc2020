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
    m_timer.Start();
}

void Robot::RobotPeriodic(){ 
    LimeLight.Update();

    driveTrain.Aim();

    driveTrain.Drive();

    shooter.Shots();
    
    climber.ClimbPeriodic();

    hopper.HopperPeriodic();
}

void Robot::AutonomousInit()     {
    m_timer.Reset();
    m_timer.Start();
}

void Robot::AutonomousPeriodic() { 
    while(m_timer.Get() < 4){
        shooterHood.Set(frc::DoubleSolenoid::Value::kForward);
        m_leftShooter.Set(.87);
        m_rightShooter.Set(.87);
        m_hopper.Set(.3);
        continue;
    }
    while(m_timer.Get() > 4 && m_timer.Get() < 5){
        m_rightBottomMotor.Set(.3);
        m_rightMiddleMotor.Set(.3);

        m_leftBottomMotor.Set(-.3);
        m_leftMiddleMotor.Set(-.3);
        continue;
    }
}

void Robot::TeleopInit(){
    shooterHood.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Robot::TeleopPeriodic(){

}

void Robot::TestInit(){
    
}

void Robot::TestPeriodic(){
    
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
