#include "shape.h"

Shape::Shape(int _type, const std::vector<int>& _coords) : type(_type), coords(_coords) {
    square = calculateSquare();
    volume = calculateVolume();
}

Shape::Shape(int _type, int x, int y, double R, double H) : type(_type), radius(R), height(H) {
    coords = {x, y};
    square = calculateSquare();
    volume = calculateVolume();
}

double Shape::calculateSquare() const {
    switch (type) {
    case line:
        return 0;
    case sqr:
        return std::abs(coords[0] - coords[2]) * std::abs(coords[1] - coords[3]);
    case cube: {
        int a = std::abs(coords[0] - coords[3]);
        int b = std::abs(coords[1] - coords[4]);
        int c = std::abs(coords[2] - coords[5]);
        return 2 * (a * b + a * c + b * c);
    }
    case circle:
        return M_PI * radius * radius;
    case cylinder:
        return 2 * M_PI * radius * (radius + height);
    default:
        return 0;
    }
}

double Shape::calculateVolume() const {
    switch (type) {
    case line:
    case sqr:
        return 0;
    case cube: {
        int a = std::abs(coords[0] - coords[3]);
        int b = std::abs(coords[1] - coords[4]);
        int c = std::abs(coords[2] - coords[5]);
        return a * b * c;
    }
    case cylinder:
        return M_PI * radius * radius * height;
    default:
        return 0;
    }
}
