/* #include<iostream>
#include<cmath> */

#include "shape.h"
//Implement an interface for shape, and derive circle, triangle, rectangle, square 
//as children. Overload all three comparison operators to compare the shapes based 
//on their area -- if equal then their perimeter should be considered. Only, and 
//if only both area and perimeter are equal then the objects should be considered equal.



int main(){

    circle c1(89);
    triangle t1(5, 8);
    rectangle r1(5, 5);
    square s1(5);


    std::vector<shape*>shapes = {&c1, &t1, &r1, &s1};
    
    c1.print();
    t1.print();
    r1.print();
    s1.print();
    for(auto i=0; i<shapes.size(); i++){
        for(auto j=i+1; j<shapes.size(); j++ ){
            if (*shapes[i] > *shapes[j]) std::cout << i << " is greater than " << j << std::endl;
            if (*shapes[i] == *shapes[j]) std::cout << i << " is equal than " << j << std::endl;
            if (*shapes[i] < *shapes[j]) std::cout << i << " is less than " << j << std::endl;
        }
    }
    return 0;
}