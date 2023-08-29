//
// Created by redeg on 26/08/2023.
//

#include "CommandReceiver.h"

void CommandReceiver::move(Printer printer, Vertex* vertices) {
    if (!printer.isRun()) {
        Serial.println("Printer is not running.");
        return;
    }

    motors::step(motors::X, (((vertices[0].getX() + printer.getMinX()) / printer.getDx()) - printer.getLocation().getX()), 1);
    motors::step(motors::Y, (((vertices[0].getY() + printer.getMinY()) / printer.getDy()) - printer.getLocation().getY()), 1);
    motors::step(motors::Z, (((vertices[0].getZ() + printer.getMinZ()) / printer.getDz()) - printer.getLocation().getZ()), 1);

    int* v = new int[9];
    auto* l = new double[3];

    v[0] = ((vertices[1].getX() - vertices[0].getX()) + printer.getMinX()) / printer.getDx();
    v[1] = ((vertices[1].getY() - vertices[0].getY()) + printer.getMinY()) / printer.getDy();
    v[2] = ((vertices[1].getZ() - vertices[0].getZ()) + printer.getMinZ()) / printer.getDz();
    l[0] = sqrt(pow(v[0]*X_MM_PER_STEP, 2) + pow(v[1]*Y_MM_PER_STEP, 2) + pow(v[2]*Z_MM_PER_STEP, 2));

    v[3] = ((vertices[2].getX() - vertices[1].getX()) + printer.getMinX()) / printer.getDx();
    v[4] = ((vertices[2].getY() - vertices[1].getY()) + printer.getMinY()) / printer.getDy();
    v[5] = ((vertices[2].getZ() - vertices[1].getZ()) + printer.getMinZ()) / printer.getDz();
    l[1] = sqrt(pow(v[3]*X_MM_PER_STEP, 2) + pow(v[4]*Y_MM_PER_STEP, 2) + pow(v[5]*Z_MM_PER_STEP, 2));

    v[6] = ((vertices[0].getX() - vertices[2].getX()) + printer.getMinX()) / printer.getDx();
    v[7] = ((vertices[0].getY() - vertices[2].getY()) + printer.getMinY()) / printer.getDy();
    v[8] = ((vertices[0].getZ() - vertices[2].getZ()) + printer.getMinZ()) / printer.getDz();
    l[2] = sqrt(pow(v[6]*X_MM_PER_STEP, 2) + pow(v[7]*Y_MM_PER_STEP, 2) + pow(v[8]*Z_MM_PER_STEP, 2));

    for (int j = 0; j < 3; j++) {
        printer.setLocation(vertices[j]);
        int step_filament = ((int)ceil((l[j] / A_MM_PER_STEP) * NOZZLE_SENSIBILITY));
        motors::step(motors::A, ceil(RETRACTION/A_MM_PER_STEP), 1);
        for (float i = 0; i < 1; i += NOZZLE_SENSIBILITY) {
            motors::step(motors::X, ((int)ceil(v[j*3] * NOZZLE_SENSIBILITY)), 1);
            motors::step(motors::Y, ((int)ceil(v[j*3 + 1] * NOZZLE_SENSIBILITY)), 1);
            motors::step(motors::Z, ((int)ceil(v[j*3 + 2] * NOZZLE_SENSIBILITY)), 1);
            motors::step(motors::A, step_filament, 1);
        }
        motors::step(motors::A, ceil(RETRACTION/A_MM_PER_STEP), -1);
    }

    printer.setLocation(vertices[0]);
}

void CommandReceiver::stop(Printer printer) {
    printer.setRun(false);

    Serial.println("Printer stopped.");
}

void CommandReceiver::run(Printer printer) {
    printer.setRun(true);

    Serial.println("Printer running.");
}

void CommandReceiver::home(Printer printer) {
    Serial.println("Homing...");

    while (!EndStop::isTriggeredX())
        motors::step(motors::X, 1, -1);

    while (!EndStop::isTriggeredY())
        motors::step(motors::Y, 1, -1);

    while (!EndStop::isTriggeredZ())
        motors::step(motors::Z, 1, -1);

    Serial.println("Homing finished.");
}

void CommandReceiver::setMinX(Printer printer, int minX) {
    printer.setMinX(minX);
    if (printer.getMaxX() != 0) {
        int dX = abs(printer.getMaxX() - printer.getMinX());
        double coordX = printer.getDimX() / X_MM_PER_STEP;

        printer.setDx((int)(ceil(dX / coordX)));
        Serial.print("Differtial X constant calculated. It's set to ");
        Serial.println(printer.getDx());
    }
    Serial.print("MinX coord set to ");
    Serial.println(minX);
}

void CommandReceiver::setMaxX(Printer printer, int maxX) {
    printer.setMaxX(maxX);
    if (printer.getMinX() != 0) {
        int dX = abs(printer.getMaxX() - printer.getMinX());
        double coordX = printer.getDimX() / X_MM_PER_STEP;

        printer.setDx((int)(ceil(dX / coordX)));
        Serial.print("Differtial X constant calculated. It's set to ");
        Serial.println(printer.getDx());
    }
    Serial.print("MaxX coord set to ");
    Serial.println(maxX);
}

void CommandReceiver::setMinY(Printer printer, int minY) {
    printer.setMinY(minY);
    if (printer.getMaxY() != 0) {
        int dY = abs(printer.getMaxY() - printer.getMinY());
        double coordY = printer.getDimY() / Y_MM_PER_STEP;

        printer.setDy((int)(ceil(dY / coordY)));
        Serial.print("Differtial Y constant calculated. It's set to ");
        Serial.println(printer.getDy());
    }
    Serial.print("MinY coord set to ");
    Serial.println(minY);
}

void CommandReceiver::setMaxY(Printer printer, int maxY) {
    printer.setMaxY(maxY);
    if (printer.getMinY() != 0) {
        int dY = abs(printer.getMaxY() - printer.getMinY());
        double coordY = printer.getDimY() / Y_MM_PER_STEP;

        printer.setDy((int)(ceil(dY / coordY)));
        Serial.print("Differtial Y constant calculated. It's set to ");
        Serial.println(printer.getDy());
    }
    Serial.print("MaxY coord set to ");
    Serial.println(maxY);
}

void CommandReceiver::setMinZ(Printer printer, int minZ) {
    printer.setMinZ(minZ);
    if (printer.getMaxZ() != 0) {
        int dZ = abs(printer.getMaxZ() - printer.getMinZ());
        double coordZ = printer.getDimZ() / Z_MM_PER_STEP;

        printer.setDz((int)(ceil(dZ / coordZ)));
        Serial.print("Differtial z constant calculated. It's set to ");
        Serial.println(printer.getDz());
    }
    Serial.print("MinZ coord set to ");
    Serial.println(minZ);
}

void CommandReceiver::setMaxZ(Printer printer, int maxZ) {
    printer.setMaxZ(maxZ);
    if (printer.getMinZ() != 0) {
        int dZ = abs(printer.getMaxZ() - printer.getMinZ());
        double coordZ = printer.getDimZ() / Z_MM_PER_STEP;

        printer.setDz((int)(ceil(dZ / coordZ)));
        Serial.print("Differtial Z constant calculated. It's set to ");
        Serial.println(printer.getDz());
    }
    Serial.print("MaxZ coord set to ");
    Serial.println(maxZ);
}

void CommandReceiver::setDimX(Printer printer, float dimX) {
    printer.setDimX(min(dimX, X_BED_SIZE));
    Serial.print("X print dimension set to ");
    Serial.println(dimX);
}

void CommandReceiver::setDimY(Printer printer, float dimY) {
    printer.setDimY(min(dimY, Y_BED_SIZE));
    Serial.print("Y print dimension set to ");
    Serial.println(dimY);
}

void CommandReceiver::setDimZ(Printer printer, float dimZ) {
    printer.setDimZ(min(dimZ, Z_BED_SIZE));
    Serial.print("Z print dimension set to ");
    Serial.println(dimZ);
}

void CommandReceiver::filament(Printer printer) {
    step(motors::A, ceil(5/A_MM_PER_STEP), 1);

    Serial.println("5mm of filament were extruded successfully");
}

void CommandReceiver::test(Printer printer) {
    Serial.println("Test started");

    for(int i = 0; i < 100; i++) {
        digitalWrite(2, HIGH);
        delay(1);
        digitalWrite(2, LOW);
    }

    /*step(motors::X, 100, 1);
    step(motors::X, 100, -1);*/
    Serial.println("Test finished");
}