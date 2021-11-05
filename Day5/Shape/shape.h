#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<cmath>
#include<vector>

class shape{
public:
    shape() = default;
    shape(const int &_p, const int &_a):circumference(_p),area(_a){}
    virtual ~shape() = 0;
    bool operator <(const shape &s);
    bool operator >(const shape &s);
    bool operator ==(const shape &s);
    void print(){
        std::cout << "Area: " << area << ", Circumference: " << circumference << std::endl;
    }
private:
    int circumference = 0, area = 0;

};

class circle:public shape{
public:
    circle(const int &radius):shape((2*radius*3),std::pow(radius,2)){}
};

class triangle:public shape{
public:
    triangle(const int &width, const int &height):shape((width/std::sqrt(3)), (width * height) / 2){}
};
class rectangle:public shape{
public:
    rectangle(const int &width, const int &height):shape((width + height) * 2, width * height){}

};
class square:public shape{
public:
    square(const int &width):shape((width * 4), width * width){}

};


#endif  // SHAPE_H