#include <iostream>
#include <cmath>
/*
Write a program to calculate field of a figure:

    plan a field hierarhy
    implement count method for all classes
    asking user to provide data in apropriate classes
    program:
        asks user to provide filed type to calculate
        call virtual count method
*/
class Shape{
public:
    virtual ~Shape() = default;
    virtual double countArea() const noexcept = 0;
};

class Rect : public Shape{
public:

    Rect(int a, int b) : _a(a), _b(b){
    	countCircles++;
    }
    virtual double countArea() const noexcept override{
        return _a * _b;
    }

private:
    double _a;
    double _b;
    static int countCircles;
};

class Triangle : public Shape{
public:
    Triangle(int h, int a) : _h(h), _a(a) {}
    virtual double countArea() const noexcept override{
        return (_a*_h)/2;
    }
private:
    double _h;
    double _a;
};

class Circle : public Shape{
public:
    Circle(double radius) : _r(radius){}
    virtual double countArea() const noexcept override{
        return M_PI * _r;
    }

private:
    double _r;
};

int main(){

	return 0;
}