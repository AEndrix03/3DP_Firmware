#include "main.h"

void setup() {
    Serial.begin(SERIAL_BAUDRATE);

    printer = *new Printer();
    listener = *new SerialListener();

    pinMode(X_STEP, OUTPUT);
    //pinMode(Y_STEP, OUTPUT);
    //pinMode(Z_STEP, OUTPUT);
    //pinMode(A_STEP, OUTPUT);

    pinMode(X_DIR, OUTPUT);
    //pinMode(Y_DIR, OUTPUT);
    //pinMode(Z_DIR, OUTPUT);
    //pinMode(A_DIR, OUTPUT);

    //pinMode(X_ENDSTOP, INPUT);
    //pinMode(Y_ENDSTOP, INPUT);
    //pinMode(Z_ENDSTOP, INPUT);


    initPrinter();
}

void loop() {
    listener.read(printer);
}

void initPrinter() {
    for (int i = 0; i < 15; i++) {
        Serial.print(i % 2 == 0 ? "-" : ".");
        delay(250);
    }

    Serial.println();
    Serial.print("Printer name: ");
    delay(250);
    Serial.println(PRINTER_NAME);
    delay(250);
    Serial.print("Author: ");
    delay(250);
    Serial.println(PRINTER_AUTHOR);
    Serial.print("Printer version: ");
    delay(250);
    Serial.println(PRINTER_VERSION);
    for (int i = 0; i < 15; i++) {
        Serial.print(i % 2 == 0 ? "-" : ".");
        delay(250);
    }

    for (int i = 0; i < 5; i++)
        Serial.println();

    Serial.println();
    Serial.print("Firmware: ");
    delay(250);
    Serial.println(FIRMWARE_NAME);
    delay(250);
    Serial.print("Firmware Author: ");
    delay(250);
    Serial.println(FIRMWARE_AUTHOR);
    Serial.print("Firmware version: ");
    delay(250);
    Serial.println(FIRMWARE_VERSION);

    for (int i = 0; i < 5; i++)
        Serial.println();

    Serial.println("Starting");
    delay(250);
    Serial.print(".");
    Serial.print(".");
    Serial.print(".");

    printer.setRun(true);

    Serial.println("Started");

    for (int i = 0; i < 3; i++)
        Serial.println();

}