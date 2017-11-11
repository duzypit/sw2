#include "Rectangle.hpp"

Rectangle::Rectangle(int a, int b) : _a(a), _b(b) {}

Rectangle::~Rectangle() {}

double Rectangle::getArea(){
	return _a * _b;
}

double Rectangle::getCircuit(){
    return 2*_a + 2*_b;
}
