//
// Created by redeg on 25/08/2023.
//

#ifndef INC_3DP_FIRMWARE_SERIAL_LISTENER_H
#define INC_3DP_FIRMWARE_SERIAL_LISTENER_H

#include "Arduino.h"
#include "CommandReceiver.h"
#include "../Printer.h"

enum CommandType : int {
    M = 1, S = 2, R = 3, x = 4, X = 5, y = 6, Y = 7, z = 8, Z = 9, A = 10, B = 11, C = 12, H = 13, F = 14, T = 15, D = 0
};

class SerialListener {
public:
    SerialListener();
    void read(Printer printer);
    void command(Printer printer, CommandType type, const char* buffer, int length);
private:
    CommandType flowControl = D;
};

#endif //INC_3DP_FIRMWARE_SERIAL_LISTENER_H
