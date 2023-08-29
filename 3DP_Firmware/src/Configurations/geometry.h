//
// Created by redeg on 25/08/2023.
//

#ifndef INC_3DP_FIRMWARE_GEOMETRY_H
#define INC_3DP_FIRMWARE_GEOMETRY_H

namespace geometry {
    //Axis MM PER STEP
    #define X_MM_PER_STEP 0.433
    #define Y_MM_PER_STEP 0.410
    #define Z_MM_PER_STEP 0.013
    #define A_MM_PER_STEP 0.287

    //Axis Max Speed
    #define X_MAX_SPEED 1
    #define Y_MAX_SPEED 1
    #define Z_MAX_SPEED 1
    #define A_MAX_SPEED 1

    //Bed Size (in mm)
    #define X_BED_SIZE 100
    #define Y_BED_SIZE 150
    #define Z_BED_SIZE 1500

    //Offsets (in mm)
    #define X_OFFSET_MIN 10
    #define Y_OFFSET_MIN 10
    #define Z_OFFSET_MIN 10

    #define X_OFFSET_MAX 90
    #define Y_OFFSET_MAX 140
    #define Z_OFFSET_MAX 200

    //Extrusors
    #define NOZZLE_SENSIBILITY 0.2 //in mm
    #define RETRACTION 5 //in mm

    #define HOME_LOCATION {X_OFFSET_MIN, Y_OFFSET_MIN, Z_OFFSET_MIN}

}
#endif //INC_3DP_FIRMWARE_GEOMETRY_H
