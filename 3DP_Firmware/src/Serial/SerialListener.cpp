//
// Created by redeg on 25/08/2023.
//

#include "SerialListener.h"
#include "../lib/Arduino-MemoryFree-master/MemoryFree.h"


void SerialListener::read(Printer printer) {
    if (Serial.available()) {
        if (flowControl == D) {
            //Questo è il primo byte ricevuto, quindi è il byte di controllo
            /*
             * M per i comandi movimento
             * S per stoppare
             * R per continuare
             * H per settare la testina alla home
             * x per controllare il minX
             * X per controllare il maxX
             * y per controllare il minY
             * Y per controllare il maxY
             * z per controllare il minZ
             * Z per controllare il maxZ
             * A per settare il DimX
             * B per settare il DimY
             * C per settare il DimZ
             * F per far andare avanti il filamento fino al prossimo comando (Utilizzato per startare la stampa)
             * T Testa il movimento di un asse (DEBUG)
             */

            switch (Serial.read()) {
                case 'M':
                    flowControl = M;
                    break;
                case 'S':
                    flowControl = S;
                    break;
                case 'R':
                    flowControl = R;
                    break;
                case 'x':
                    flowControl = x;
                    break;
                case 'X':
                    flowControl = X;
                    break;
                case 'y':
                    flowControl = y;
                    break;
                case 'Y':
                    flowControl = Y;
                    break;
                case 'z':
                    flowControl = z;
                    break;
                case 'Z':
                    flowControl = Z;
                    break;
                case 'A':
                    flowControl = A;
                    break;
                case 'B':
                    flowControl = B;
                    break;
                case 'C':
                    flowControl = C;
                    break;
                case 'H':
                    flowControl = H;
                    break;
                case 'F':
                    flowControl = F;
                    break;
                case 'T':
                    flowControl = T;
                    break;
                default:
                    flowControl = D;
                    break;
            }
        }

        // Leggi il byte ricevuto dalla porta seriale
        char receivedByte = Serial.read();
        //crea un oggetto char* dove posso salvare un numero indefinito di char
        char* buffer = new char[50];
        int length = 0;

        while (receivedByte != ';') {
            if (length >= 50)
                break;

            buffer[length] = receivedByte;
            length++;

            receivedByte = Serial.read();
        }

        char* newBuffer = new char[length];
        for (int i = 0; i < length; i++)
            newBuffer[i] = buffer[i];

        Serial.print("Free memory: ");
        Serial.println(freeMemory());

        delete[] buffer;

        Serial.print("Free memory: ");
        Serial.println(freeMemory());

        command(printer, flowControl, newBuffer, length);

        flowControl = D;
    }
}

void SerialListener::command(Printer printer, CommandType type, const char* buffer, int length) {
    switch (type) {
        case M: {
            //Triangle 3 Vertex with 3 points, x,y,z,x,y,z,x,y,z

            int* vertexesCoords = new int[9];
            for (int i = 0; i < 9; i++)
                vertexesCoords[i] = 0;

            int c = 0;

            for (int i = 0; i < length; i++) {
                while (buffer[i] != ',' && i < length) {
                    vertexesCoords[c] = vertexesCoords[c] * 10 + (int) buffer[i];
                    i++;
                }
                c++;
            }

            auto* vertexes = new Vertex[3];
            for (int i = 0; i < 3; i++)
                vertexes[i] = Vertex(vertexesCoords[i * 3], vertexesCoords[i * 3 + 1], vertexesCoords[i * 3 + 2]);

            CommandReceiver::move(printer, vertexes);
            break;
        }
        case S:
            CommandReceiver::stop(printer);
            break;
        case R:
            CommandReceiver::run(printer);
            break;
        case x: {
            int minX = 0;
            for (int i = 0; i < length; i++)
                minX = minX * 10 + (int) buffer[i];

            CommandReceiver::setMinX(printer, minX);
            break;
        }
        case X: {
            int maxX = 0;
            for (int i = 0; i < length; i++)
                maxX = maxX * 10 + (int) buffer[i];

            CommandReceiver::setMaxX(printer, maxX);
            break;
        }
        case y: {
            int minY = 0;
            for (int i = 0; i < length; i++)
                minY = minY * 10 + (int) buffer[i];

            CommandReceiver::setMinY(printer, minY);
            break;
        }
        case Y: {
            int maxY = 0;
            for (int i = 0; i < length; i++)
                maxY = maxY * 10 + (int) buffer[i];

            CommandReceiver::setMaxY(printer, maxY);
            break;
        }
        case z: {
            int minZ = 0;
            for (int i = 0; i < length; i++)
                minZ = minZ * 10 + (int) buffer[i];

            CommandReceiver::setMinZ(printer, minZ);
            break;
        }
        case Z: {
            int maxZ = 0;
            for (int i = 0; i < length; i++)
                maxZ = maxZ * 10 + (int) buffer[i];

            CommandReceiver::setMaxZ(printer, maxZ);
            break;
        }
        case A: {
            float dimX = 0;
            int X = 0;
            int i = 0;

            while (buffer[i] != '.') {
                X = X * 10 + (int) buffer[i];
                i++;
            }

            i++;

            while (buffer[i] != '.') {
                dimX = dimX / 10 + (int) buffer[i];
                i++;
            }

            dimX /= 10;
            dimX += X;

            CommandReceiver::setDimX(printer, dimX);
            break;
        }
        case B: {
            float dimY = 0;
            int Y = 0;
            int i = 0;

            while (buffer[i] != '.') {
                Y = Y * 10 + (int) buffer[i];
                i++;
            }

            i++;

            while (buffer[i] != '.') {
                dimY = dimY / 10 + (int) buffer[i];
                i++;
            }

            dimY /= 10;
            dimY += Y;

            CommandReceiver::setDimY(printer, dimY);
            break;
        }
        case C: {
            float dimZ = 0;
            int Z = 0;
            int i = 0;

            while (buffer[i] != '.') {
                Z = Z * 10 + (int) buffer[i];
                i++;
            }

            i++;

            while (buffer[i] != '.') {
                dimZ = dimZ / 10 + (int) buffer[i];
                i++;
            }

            dimZ /= 10;
            dimZ += Z;

            CommandReceiver::setDimZ(printer, dimZ);
            break;
        }
        case H:
            CommandReceiver::home(printer);
            break;
        case F: {
            CommandReceiver::filament(printer);
            break;
        }
        case T: {
            CommandReceiver::test(printer);
            break;
        }
        case D:
            Serial.println("Command buffer resetted.");
            break;
        default:
            break;

    }

}

SerialListener::SerialListener() = default;
