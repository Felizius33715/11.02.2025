/* 

functions replaced in shape.cpp


#include "transform.h"

Shape Transform::shift(int dx, int dy, int dz) {
    for (size_t i = 0; i < shape.coords.size(); i += 3) {
        shape.coords[i] += dx;
        if (i + 1 < shape.coords.size()) shape.coords[i + 1] += dy;
        if (i + 2 < shape.coords.size()) shape.coords[i + 2] += dz;
    }
    return shape;
}

Shape Transform::scale(int factor) {
    for (size_t i = 0; i < shape.coords.size(); ++i) {
        shape.coords[i] *= factor;
    }
    return shape;
}

Shape Transform::scaleX(int factor) {
    applyTransform(0, factor, 'x');
    return shape;
}

Shape Transform::scaleY(int factor) {
    applyTransform(1, factor, 'y');
    return shape;
}

Shape Transform::scaleZ(int factor) {
    applyTransform(2, factor, 'z');
    return shape;
}

void Transform::applyTransform(int index, int factor, char axis) {
    for (size_t i = index; i < shape.coords.size(); i += 3) {
        shape.coords[i] *= factor;
    }
}
*/
