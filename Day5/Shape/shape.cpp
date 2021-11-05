#include "shape.h"


bool shape::operator <(const shape &s) {
    bool returnVal = false;
    if ( (this->area < s.area) ||
         ( (this->area == s.area) && (this->circumference < s.circumference) ) )
        returnVal = true;    
    return returnVal;
}

bool shape::operator >(const shape &s) {
    bool returnVal = false;
    if ( (this->area > s.area) ||
         ( (this->area == s.area) && (this->circumference > s.circumference) ) )
        returnVal = true;    
    return returnVal;
}

bool shape::operator ==(const shape &s) {
    bool returnVal = false;
    if ( (this->area == s.area) && (this->circumference == s.circumference) ) 
        returnVal = true;    
    return returnVal;
}
shape::~shape(){}