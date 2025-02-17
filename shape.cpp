#pragma once
#include <vector>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default;

    virtual void shift(int dx, int dy, int dz = 0) {
        x += dx;
        y += dy;
        z += dz;
    }

    virtual void scaleX(int factor) {
        x *= factor;
    }

    virtual void scaleY(int factor) {
        y *= factor;
    }

    virtual void scaleZ(int factor) {
        z *= factor;
    }

    virtual void scale(int factor) {
        scaleX(factor);
        scaleY(factor);
        scaleZ(factor);
    }

    virtual double getSquare() const = 0;
    virtual double getVolume() const = 0;

protected:
    int x = 0, y = 0, z = 0;
};

class Line : public Shape {
public:
    Line(int _x1, int _y1, int _x2, int _y2) 
        : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    void shift(int dx, int dy, int dz = 0) override {
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
    }

    void scaleX(int factor) override {
        x1 *= factor; x2 *= factor;
    }

    void scaleY(int factor) override {
        y1 *= factor; y2 *= factor;
    }

    void scaleZ(int factor) override {}

    void scale(int factor) override {
        scaleX(factor);
        scaleY(factor);
    }

    double getSquare() const override {
        return 0;
    }

    double getVolume() const override {
        return 0;
    }

private:
    int x1, y1, x2, y2;
};

class Rectangle : public Shape {
public:
    Rectangle(int _x, int _y, int width, int height)
        : width(width), height(height) {
        x = _x;
        y = _y;
    }

    double getSquare() const override {
        return width * height;
    }

    double getVolume() const override {
        return 0;
    }

    void scaleX(int factor) override {
        width *= factor;
    }

    void scaleY(int factor) override {
        height *= factor;
    }

    void scaleZ(int factor) override {}

private:
    int width, height;
};

class Cube : public Shape {
public:
    Cube(int _x, int _y, int _z, int size) 
        : size(size) {
        x = _x;
        y = _y;
        z = _z;
    }

    double getSquare() const override {
        return 6 * size * size;
    }

    double getVolume() const override {
        return size * size * size;
    }

    void scaleX(int factor) override {
        size *= factor;
    }

    void scaleY(int factor) override {
        size *= factor;
    }

    void scaleZ(int factor) override {
        size *= factor;
    }

private:
    int size;
};
