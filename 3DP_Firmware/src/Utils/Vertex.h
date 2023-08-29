//
// Created by redeg on 25/08/2023.
//

#ifndef INC_3DP_FIRMWARE_VERTEX_H
#define INC_3DP_FIRMWARE_VERTEX_H

class Vertex {
public:
    Vertex();
    Vertex(int x, int y, int z);
    int getX();
    int getY();
    int getZ();
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    Vertex subtract(Vertex vertex);
    Vertex add(Vertex vertex);
    Vertex multiply(Vertex vertex);
    Vertex divide(Vertex vertex);

private:
    int x{};
    int y{};
    int z{};
};

#endif //INC_3DP_FIRMWARE_VERTEX_H
