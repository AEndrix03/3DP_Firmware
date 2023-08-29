//
// Created by redeg on 25/08/2023.
//
#include "motors.h"

void motors::step(motors::Motor motor, int steps, int dir) {
    int pinStep = 0, pinDir, speed;

    if (steps == 0)
        return;
    else if (steps < 0) {
        steps *= -1;
        dir *= -1;
    }

    switch (motor) {
        case motors::X: {
            dir *= X_INVERT_DIRECTION ? -1 : 1;
            speed = X_MAX_SPEED;
            pinStep = X_STEP;
            pinDir = X_DIR;
        }
        case motors::Y: {
            dir *= Y_INVERT_DIRECTION ? -1 : 1;
            speed = Y_MAX_SPEED;
            pinStep = Y_STEP;
            pinDir = Y_DIR;
        }
        case motors::Z: {
            dir *= Z_INVERT_DIRECTION ? -1 : 1;
            speed = Z_MAX_SPEED;
            pinStep = Z_STEP;
            pinDir = Z_DIR;
        }
        case motors::A: {
            dir *= A_INVERT_DIRECTION ? -1 : 1;
            speed = A_MAX_SPEED;
            pinStep = A_STEP;
            pinDir = A_DIR;
        }
    }

    if (dir > 0)
        digitalWrite(pinDir, HIGH);
    else
        digitalWrite(pinDir, LOW);

    for (int i = 0; i < steps; i++) {
        digitalWrite(pinStep, HIGH);
        delay(speed);
        digitalWrite(pinStep, LOW);
    }

}

void testEndStopXAxis() {
    Serial.println("...");

    int c = 0;
    int dir = -1;
    int steps = 0;

    while (true) {
        if (EndStop::isTriggeredX()){
            if (c == 0) {
                Serial.println("X Min EndStop touched. Start measuring...");
                dir = 1;
                steps = 0;
            } else {
                Serial.println("X Max EndStop touched. Finish measuring.");
                Serial.print("Steps: ");
                Serial.println(steps);
            }
            c++;
        }

        if (c > 1)
            break;
        step(motors::X, 1, dir);
        steps++;
    }

    Serial.println("...");
}

void testEndStopYAxis() {
    Serial.println("...");

    int c = 0;
    int dir = -1;
    int steps = 0;

    while (true) {
        if (EndStop::isTriggeredY()){
            if (c == 0) {
                Serial.println("Y Min EndStop touched. Start measuring...");
                dir = 1;
                steps = 0;
            } else {
                Serial.println("Y Max EndStop touched. Finish measuring.");
                Serial.print("Steps: ");
                Serial.println(steps);
            }
            c++;
        }

        if (c > 1)
            break;
        step(motors::Y, 1, dir);
        steps++;
    }

    Serial.println("...");
}

void testEndStopZAxis() {
    Serial.println("...");

    int c = 0;
    int dir = -1;
    int steps = 0;

    while (true) {
        if (EndStop::isTriggeredZ()){
            if (c == 0) {
                Serial.println("Z Min EndStop touched. Start measuring...");
                dir = 1;
                steps = 0;
            } else {
                Serial.println("Z Max EndStop touched. Finish measuring.");
                Serial.print("Steps: ");
                Serial.println(steps);
            }
            c++;
        }

        if (c > 1)
            break;
        step(motors::Z, 1, dir);
        steps++;
    }

    Serial.println("...");
}

void motors::retraction(motors::Motor motor) {
    motors::step(motor, ceil(RETRACTION/A_MM_PER_STEP), -1);
}

void motors::unretraction(motors::Motor motor) {
    motors::step(motor, ceil(RETRACTION/A_MM_PER_STEP), 1);
}

