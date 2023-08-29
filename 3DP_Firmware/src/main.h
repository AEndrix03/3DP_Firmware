//
// Created by redeg on 26/08/2023.
//

#ifndef INC_3DP_FIRMWARE_MAIN_H
#define INC_3DP_FIRMWARE_MAIN_H

#include "Arduino.h"
#include "Printer.h"
#include "Serial/SerialListener.h"
#include "Configurations/general.h"
#include "Configurations/pins.h"


static Printer printer;
static SerialListener listener;

void initPrinter();

#endif //INC_3DP_FIRMWARE_MAIN_H
