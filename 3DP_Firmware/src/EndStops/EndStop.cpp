//
// Created by redeg on 26/08/2023.
//

#include "EndStop.h"

bool EndStop::isTriggeredX() {
    return digitalRead(X_ENDSTOP) == HIGH;
}

bool EndStop::isTriggeredY() {
    return digitalRead(Y_ENDSTOP) == HIGH;
}

bool EndStop::isTriggeredZ() {
    return digitalRead(Z_ENDSTOP) == HIGH;
}