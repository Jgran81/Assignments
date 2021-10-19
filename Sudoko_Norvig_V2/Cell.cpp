#include <iostream>
#include "Cell.hh"

Cell::Cell(int row, int col){           //Starting value of each object is set to 0
    this->value = 0;
    this->row = row;
    this->col = col;
}
Cell::Cell(int value){  //sending a value will set value for obj and flag it true
    this->value = value;
    isSet = true;
    
}
void Cell::setCell(int value){
    this->value = value;
    isSet = true;
    for(int i=0; i<9; i++){
        hypArray[i] = 0;
    }
}
int Cell::getValue(){
    return value;
}
bool Cell::getState(){
    return isSet;
}
int Cell::getRow(){
    return row;
};
int Cell::getCol(){
    return col;
};
int Cell::getHyp(int i){
    return hypArray[i];
};
void Cell::printCell(){
    //std::cout << "R, C: " << row << ", " << col;
    if(isSet == true){
        std::cout << " " << value << " " ;    //If the Cell is set, print value
    }
    else{
        std::cout << " . " ;      //Else print .
    }
}
void Cell::removeFromHyp(int a){    //Remove from hypothetical numbers list, gets the number that will be removed, checks if one number is left and sets that to value and flag true
    if(hypArray[a-1] > 0){          //If the corresponding position in the hyp array is set to 1 = true
        hypArray[a-1] -= a;         //Set the value of hyparray to 0
        int checker = 0;            //Checker to add numbers of array
        int position;               //Position saver for last set number
        for(int i=0; i<9; i++){    //Loop over hyparray to add all numbers
            checker += hypArray[i]; //Add to checker
            if(hypArray[i] == 1){
                position = i +1;    //Set position if location have 1
            }
            if(checker > 0){        //If more then one 1, break from loop
                break;
            }
            if(checker == 1 && i == 9){ //If only one 1 and at the end of loop = true
                value = position;            //Set value of object to the position from hyparray
                isSet = true;          //Set the flag to true
                //peer(sudokuBoard, i, j);
            }
        }
    }
}
void Cell::printHyp(){
    /* if(isSet){
        this->printCell();
        //std::cout << std::endl;
    } */
    
        std::cout << " ( ";
        for(int i=0; i<9; i++){
            if(hypArray[i] > 0){
                std::cout << i+1 << ", ";
            }
        }
        std::cout << ")   ";
    
};

Cell::~Cell(){
}