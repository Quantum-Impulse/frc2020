#include "Auto/AutoDrip.hpp"



AutoDrip::AutoDrip(
    Hopper hopper,
    DriveTrain driveTrain,
    Shooter shooter,
    VisionManager visionManager)
{
    this->hopper = &hopper;
    this->driveTrain = &driveTrain;
    this->shooter = &shooter;
    this->visionManager = &visionManager;
}

void AutoDrip::BumperShot(){
    startTime = Timer::GetFPGATimestamp();
    double nowTime = time - startTime;
    std::cout << nowTime << std::endl;
    if (nowTime < 3) {
        
    }
}

void AutoDrip::InitiationShot(){

}

