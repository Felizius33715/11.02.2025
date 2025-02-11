#pragma once
#include "shape.h"

class Transform {
public:
    Transform(const Shape& sh) : shape(sh) {}

    Shape shift(int dx, int dy, int dz = 0);
    Shape scale(int factor);
    Shape scaleX(int factor);
    Shape scaleY(int factor);
    Shape scaleZ(int factor);

private:
    Shape shape;
    void applyTransform(int index, int factor, char axis);
};
