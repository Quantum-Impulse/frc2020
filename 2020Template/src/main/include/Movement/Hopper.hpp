#ifndef HOPPER_HPP
#define HOPPER_HPP

#include "rev/CANSparkMax.h"
#include "Movement/ControllerManager.hpp"

/* CAN ID layout for drive train from a top view

          Front of Robot
         
         |--------------|
         |              |
         |              | 
         |              | 
         |              | 
         |              |
         |              |
         |--------------|

          Back Of Robot
*/

class Hopper{
    public:

    Hopper(
        rev::CANSparkMax &Belt);
    void Advance();
    void CheckAdvance();
    void ManualControl();
    
    private:
    FRC5572Controller* Operator;
    rev::CANSparkMax* Belt;
};

#endif