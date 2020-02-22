#ifndef CLIMB_MANAGER_HPP
#define CLIMB_MANAGER_HPP

#include <frc/DoubleSolenoid.h>
#include "rev/CANSparkMax.h"
#include <frc/SpeedControllerGroup.h>
#include "Movement/ControllerManager.hpp"

class ClimbManager {
 public:
  ClimbManager(
    rev::CANSparkMax& leftClimb,
    rev::CANSparkMax& rightClimb,
    FRC5572Controller& Driver,
    frc::DoubleSolenoid& climbPistons
  );

  void Up();
  void Down();
  void Spin();
  private:
  frc::SpeedControllerGroup* climbMotors;

  FRC5572Controller* driver;

  rev::CANSparkMax* leftClimb;
  rev::CANSparkMax* rightClimb;

  frc::DoubleSolenoid* climbPistons;

};
#endif