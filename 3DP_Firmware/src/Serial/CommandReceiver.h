//
// Created by redeg on 26/08/2023.
//

#ifndef INC_3DP_FIRMWARE_COMMANDRECEIVER_H
#define INC_3DP_FIRMWARE_COMMANDRECEIVER_H

#include "Arduino.h"
#include "../Utils/Vertex.h"
#include "../Configurations/geometry.h"
#include "../Motors/motors.h"
#include "../Endstops/EndStop.h"
#include "Printer.h"


namespace CommandReceiver {

    void move(Printer printer, Vertex *vertices);
    void stop(Printer printer);
    void run(Printer printer);
    void home(Printer printer);
    void setMinX(Printer printer, int minX);
    void setMaxX(Printer printer, int maxX);
    void setMinY(Printer printer, int minY);
    void setMaxY(Printer printer, int maxY);
    void setMinZ(Printer printer, int minZ);
    void setMaxZ(Printer printer, int maxZ);
    void setDimX(Printer printer, float dimX);
    void setDimY(Printer printer, float dimY);
    void setDimZ(Printer printer, float dimZ);
    void filament(Printer printer);
    void test(Printer printer);
}

#endif //INC_3DP_FIRMWARE_COMMANDRECEIVER_H
