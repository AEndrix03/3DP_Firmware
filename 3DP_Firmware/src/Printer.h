//
// Created by redeg on 26/08/2023.
//

#ifndef INC_3DP_FIRMWARE_PRINTER_H
#define INC_3DP_FIRMWARE_PRINTER_H

#include "Utils/Vertex.h"

class Printer {
public:
    Printer();
    void setMinX(int minX);
    void setMaxX(int maxX);
    void setMinY(int minY);
    void setMaxY(int maxY);
    void setMinZ(int minZ);
    void setMaxZ(int maxZ);
    int getMinX();
    int getMaxX();
    int getMinY();
    int getMaxY();
    int getMinZ();
    int getMaxZ();
    int getDx() const;
    void setDx(int dX);
    int getDy() const;
    void setDy(int dY);
    int getDz() const;
    void setDz(int dZ);
    int getMaxCoordX() const;
    void setMaxCoordX(int maxCoordX);
    int getMaxCoordY() const;
    void setMaxCoordY(int maxCoordY);
    int getMaxCoordZ() const;
    void setMaxCoordZ(int maxCoordZ);
    float getDimX() const;
    void setDimX(float dimX);
    float getDimY() const;
    void setDimY(float dimY);
    float getDimZ() const;
    void setDimZ(float dimZ);
    bool isRun() const;
    void setRun(bool run);
    Vertex getLocation() const;
    void setLocation(Vertex location);

private:
    Vertex location;
    bool run = false;
    int minX = 0;
    int maxX = 0;
    int minY = 0;
    int maxY = 0;
    int minZ = 0;
    int maxZ = 0;
    int dX = 1;
    int dY = 1;
    int dZ = 1;
    int maxCoordX = 0;
    int maxCoordY = 0;
    int maxCoordZ = 0;
    float dimX = 0;
    float dimY = 0;
    float dimZ = 0;
};


#endif //INC_3DP_FIRMWARE_PRINTER_H
