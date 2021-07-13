#include "Shape.hpp"

Shape::Shape() {
    area = 0;
    perimeter = 0;
}

// Setters
void Shape::SetArea(float a) {
    area = a;
}

void Shape::SetPerimeter(float p) {
    perimeter = p;
}

// Getters
float Shape::GetArea() {
    return area;
}

float Shape::GetPerimeter() {
    return perimeter;
}

