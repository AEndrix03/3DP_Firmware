//
// Created by redeg on 25/08/2023.
//

#ifndef INC_3DP_FIRMWARE_MOTORS_H
#define INC_3DP_FIRMWARE_MOTORS_H

#include "../Configurations/geometry.h"
#include "../Configurations/pins.h"
#include "../Endstops/EndStop.h"

namespace motors {
    enum Motor : int {
        X = 0, Y = 1, Z = 2, A = 3
    };

    //Driver type of each motor/axis
    #define X_DRIVER A4988
    #define Y_DRIVER A4988
    #define Z_DRIVER A4988
    #define A_DRIVER A4988

    //Motor invert direction (true = Normally left on positive step)
    #define X_INVERT_DIRECTION false
    #define Y_INVERT_DIRECTION false
    #define Z_INVERT_DIRECTION true
    #define A_INVERT_DIRECTION true

    //Enable motor doing steps with a certain direction (-1 = left)
    void step(Motor motor, int steps, int dir);
    void retraction(Motor motor);
    void unretraction(Motor motor);
    void testEndStopXAxis();
    void testEndStopYAxis();
    void testEndStopZAxis();

}
#endif //INC_3DP_FIRMWARE_MOTORS_H
