#pragma once
#include <vector>
#include <cmath>

class Shape {
public:
    static const int line = 0;
    static const int sqr = 1;
    static const int cube = 2;
    static const int circle = 3;
    static const int cylinder = 4;

    Shape() = default;
    Shape(int type, const std::vector<int>& coords);
    Shape(int type, int x, int y, double R, double H = 0);

    int getType() const { return type; }

    double calculateSquare() const;
    double calculateVolume() const;

    std::vector<int> coords; // Координаты фигуры
    int type = line;
    double volume = 0;
    double square = 0;
    double height = 0;
    double radius = 0;
};
