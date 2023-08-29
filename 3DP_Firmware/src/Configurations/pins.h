//
// Created by redeg on 25/08/2023.
//

#ifndef INC_3DP_FIRMWARE_PINS_H
#define INC_3DP_FIRMWARE_PINS_H

namespace pins {
    //Movement of the Stepper Motors
    #define X_STEP 2
    #define Y_STEP 3
    #define Z_STEP 4
    #define A_STEP 12

    //Direction of the Stepper Motors
    #define X_DIR 5
    #define Y_DIR 6
    #define Z_DIR 7
    #define A_DIR 13

    //End Stops of the Axis
    #define X_ENDSTOP 9
    #define Y_ENDSTOP 10
    #define Z_ENDSTOP 11
}

#endif //INC_3DP_FIRMWARE_PINS_H
