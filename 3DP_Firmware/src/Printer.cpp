//
// Created by redeg on 26/08/2023.
//

#include "Printer.h"

Printer::Printer() {
    location = *new Vertex(0, 0, 0);
}

void Printer::setMinX(int minX) {
    this->minX = minX;
}

void Printer::setMaxX(int maxX) {
    this->maxX = maxX;
}

void Printer::setMinY(int minY) {
    this->minY = minY;
}

void Printer::setMaxY(int maxY) {
    this->maxY = maxY;
}

void Printer::setMinZ(int minZ) {
    this->minZ = minZ;
}

void Printer::setMaxZ(int maxZ) {
    this->maxZ = maxZ;
}

int Printer::getMinX() {
    return minX;
}

int Printer::getMaxX() {
    return maxX;
}

int Printer::getMinY() {
    return minY;
}

int Printer::getMaxY() {
    return maxY;
}

int Printer::getMinZ() {
    return minZ;
}

int Printer::getMaxZ() {
    return maxZ;
}

int Printer::getDx() const {
    return dX;
}

void Printer::setDx(int dX) {
    Printer::dX = dX;
}

int Printer::getDy() const {
    return dY;
}

void Printer::setDy(int dY) {
    Printer::dY = dY;
}

int Printer::getDz() const {
    return dZ;
}

void Printer::setDz(int dZ) {
    Printer::dZ = dZ;
}

int Printer::getMaxCoordX() const {
    return maxCoordX;
}

void Printer::setMaxCoordX(int maxCoordX) {
    Printer::maxCoordX = maxCoordX;
}

int Printer::getMaxCoordY() const {
    return maxCoordY;
}

void Printer::setMaxCoordY(int maxCoordY) {
    Printer::maxCoordY = maxCoordY;
}

int Printer::getMaxCoordZ() const {
    return maxCoordZ;
}

void Printer::setMaxCoordZ(int maxCoordZ) {
    Printer::maxCoordZ = maxCoordZ;
}

float Printer::getDimX() const {
    return dimX;
}

void Printer::setDimX(float dimX) {
    Printer::dimX = dimX;
}

float Printer::getDimY() const {
    return dimY;
}

void Printer::setDimY(float dimY) {
    Printer::dimY = dimY;
}

float Printer::getDimZ() const {
    return dimZ;
}

void Printer::setDimZ(float dimZ) {
    Printer::dimZ = dimZ;
}

void Printer::setRun(bool run) {
    Printer::run = run;
}

bool Printer::isRun() const {
    return run;
}

Vertex Printer::getLocation() const {
    return location;
}

void Printer::setLocation(Vertex location) {
    Printer::location = location;
}

