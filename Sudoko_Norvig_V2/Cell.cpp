#include <iostream>
#include <vector>
#include <algorithm>
#include "Cell.hh"

Cell::Cell(int row, int col){           //Starting value of each object is set to 0
    this->value = 0;
    this->row = row;
    this->col = col;
}
Cell::Cell(int value){  //sending a value will set value for obj and flag it true
    this->value = value;
    set = true;
    
}
void Cell::setCell(int value){
    this->value = value;
    set = true;
    hypVector.clear();
}
int Cell::getValue(){
    return value;
}
bool Cell::isSet(){
    return set;
}
int Cell::getRow(){
    return row;
};
int Cell::getCol(){
    return col;
};
void Cell::printCell(){
    //std::cout << "R, C: " << row << ", " << col;
    if(set == true){
        std::cout << " " << value << " " ;    //If the Cell is set, print value
    }
    else{
        std::cout << " . " ;      //Else print .
    }
}
void Cell::removeFromHyp(int a){    //Remove from hypothetical numbers list, gets the number that will be removed, checks if one number is left and sets that to value and flag true
    if (std::find(hypVector.begin(), hypVector.end(), a) != hypVector.end()){
        //remove value from vector
        hypVector.erase(std::remove(hypVector.begin(), hypVector.end(), a), hypVector.end());   //Erases value a from hypVector
    }
    if (hypVector.size() == 1){
        value = hypVector[0];
        set = true;
        hypVector.clear();
    }
}
void Cell::printHyp(){
    if(set){
        this->printCell();
    } 
    else{
        std::cout << " ( ";
        for(int i=0; i<hypVector.size(); i++){
            
            std::cout << hypVector[i] << ", ";
            
        }
        std::cout << ")   ";
    }
    
};
