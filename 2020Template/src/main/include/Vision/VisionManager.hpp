#ifndef VisionManager_HPP
#define VisionManager_HPP

#include "Networktables/NetworkTable.h"
#include "Networktables/NetworkTableInstance.h"

class VisionManager
{
    public:
    double 
      disX = 0
    , disY = 0
    , tx = 0
    , ty = 0
    , ta = 0
    , tv = 0;

    bool targetFound = false;
    VisionManager();
};
#endif