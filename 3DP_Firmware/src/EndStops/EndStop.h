//
// Created by redeg on 26/08/2023.
//

#ifndef INC_3DP_FIRMWARE_ENDSTOP_H
#define INC_3DP_FIRMWARE_ENDSTOP_H

#include "Arduino.h"
#include "../Configurations/pins.h"

namespace EndStop {
    bool isTriggeredX();
    bool isTriggeredY();
    bool isTriggeredZ();
}

#endif //INC_3DP_FIRMWARE_ENDSTOP_H
