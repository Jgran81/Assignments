#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include "Cell.hh"

const int row = 9;
const int col = 9;

void sudokuSolver(std::string s);
void printInitialState(std::string s);
std::vector<Cell*>sudokuRow(Cell *sudokuBoard[row][col], int x, int y);
std::vector<Cell*>sudokuCol(Cell *sudokuBoard[row][col], int x, int y);
std::vector<Cell*>sudokuBox(Cell *sudokuBoard[row][col], int x, int y);
void peer(Cell *sudokuBoard[row][col], int x, int y);
void uniqueCandidate(Cell *sudokuBoard[row][col], int x, int y);
void printHypoState(Cell *sudokuBoard[row][col]);
void printAfterSecondRule(Cell *sudokuBoard[row][col]);

//1. If a square has only one possible value, then eliminate that value from the square’s peers.
//2. If a unit has only one possible place for a value, then put the value there.

void sudokuSolver(std::string s){
    std::string letter;
    int num;
    std::vector<int> vec;
    for(int i=0; i<s.size(); i++){
        if (s[i] != '.'){
            letter = s[i];
            num = stoi(letter);
            vec.push_back(num);
        }
        else{
            vec.push_back(0);
        }
    }
    /* for(int i=0; i<vec.size(); i++){
        std::cout << vec[i];
    } */
    Cell *sudokuBoard[row][col] = {};
    //Creating pointers to all objects in dynamic mem. 
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sudokuBoard[i][j] = new Cell(i, j);
        }
    }
    int v=0;
    int set;
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
                set = vec[v];
                if (set > 0){
                    sudokuBoard[i][j]->setCell(set);
                    peer(sudokuBoard, i, j);
                }

            
            v++; 
        }
    }
    printHypoState(sudokuBoard);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!sudokuBoard[i][j]->isSet()){
                uniqueCandidate(sudokuBoard, i, j);
            }
        }
    }

    printAfterSecondRule(sudokuBoard); 
     
    //Return memory
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            delete sudokuBoard[i][j];
            sudokuBoard[i][j] = nullptr;
            
        }
    }
}

void printAfterSecondRule(Cell *sudokuBoard[row][col]){

    std::cout << "~~~AFTER 2:ND RULE~~~" << std::endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sudokuBoard[i][j]->printCell();
            if (j == 2 || j == 5){
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i == 2 || i == 5){
            std::cout << " ~~~~~~~~+~~~~~~~~~+~~~~~~~~" << std::endl;
        }
    }
}

void printHypoState(Cell *sudokuBoard[row][col]){

    std::cout << "~~~AFTER 1:ST RULE~~~" << std::endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if (sudokuBoard[i][j]->isSet()){
                sudokuBoard[i][j]->printCell();
            }
            else{
                sudokuBoard[i][j]->printHyp();
            }
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::endl;
}

void printInitialState(std::string s){

    std::cout << "~~~INITIAL STATE~~~";
    for(int i=0; i<81; i++){
        if(i%9 == 0){
            std::cout << std::endl;
            
        }
        if(i%27 == 0 && i != 0){
            std::cout << "~~~~~~~~+~~~~~~~+~~~~~~" << std::endl;
        }
        if(i%3 == 0){
            std::cout << "| ";
        }
        if (s[i]<='9' && s[i]>= '0'){
            std::cout << s[i] << " ";
        }
        else{
            std::cout << ". ";
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;
    
    
}

//Returns vector with pointers to row cells
std::vector<Cell*>sudokuRow(Cell *sudokuBoard[row][col], int x, int y){
    
    std::vector<Cell*>rowList;
    
    int listIt = 0;
    for(int i=0; i<9; i++){
        if(y != i){  
            rowList.push_back(sudokuBoard[x][i]);
            listIt++;
        }
    }
    //Size will be 8
    return rowList;
};
//Returns vector with pointers to column cells
std::vector<Cell*>sudokuCol(Cell *sudokuBoard[row][col], int x, int y){

    std::vector<Cell*>colList;

    int listIt = 0;
    for(int i=0; i<9; i++){
        if(x != i){
            colList.push_back(sudokuBoard[i][y]);
            listIt++;
        }
    }
    //Size will be 8
    return colList;
};
//Returns vector with pointers to box cells
std::vector<Cell*>sudokuBox(Cell *sudokuBoard[row][col], int x, int y){

    std::vector<Cell*>boxList;

    int listIt = 0;
    int startRow = x - x %3;    //Set box in row
    int startCol = y - y %3;    //Set box in col
    for(int i=startRow; i<(startRow+3); i++){  
        
        for(int j=startCol; j<(startCol+3); j++){
            if(sudokuBoard[x][y] != sudokuBoard[i][j]){
                boxList.push_back(sudokuBoard[i][j]);
                listIt++;
            }
        }
    }
    //Size will be 8
    return boxList;
};

void peer(Cell *sudokuBoard[row][col], int x, int y){    

    //Get rowList and remove hypothetical values from cells in that list
    std::vector<Cell*>rowList = sudokuRow(sudokuBoard, x, y);
    for(int i=0; i<rowList.size(); i++){
        if(!rowList[i]->isSet()){   //Checks if cell already set
            rowList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());   //Removes from hypothetical array
            if(rowList[i]->isSet()){         //If value gets assigned
                peer(sudokuBoard, rowList[i]->getRow(), rowList[i]->getCol());  //Recursion if value gets set
            }
        }
        
    }
    
    //Get colList and remove hypothetical values from cells in that list
    std::vector<Cell*>colList = sudokuCol(sudokuBoard, x, y);
    for(int i=0; i<colList.size(); i++){
        if(!colList[i]->isSet()){    //Checks if cell already set
            colList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());   //Removes from hypothetical array
            if(colList[i]->isSet()){
                peer(sudokuBoard, colList[i]->getRow(), colList[i]->getCol());
            }
        }
    }
    
    //Get cboxList and remove hypothetical values from cells in that list
    std::vector<Cell*>boxList = sudokuBox(sudokuBoard, x, y);
    for(int i=0; i<boxList.size(); i++){
        if(!boxList[i]->isSet()){
            boxList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());
            if(boxList[i]->isSet()){
                peer(sudokuBoard, boxList[i]->getRow(), boxList[i]->getCol());
            }
        }
        
    }
};


void uniqueCandidate(Cell *sudokuBoard[row][col], int x, int y){

    int vecSize = sudokuBoard[x][y]->hypVector.size(); //size of vector
    
    for(int s=0; s<vecSize; s++){
       
        if (sudokuBoard[x][y]->isSet()){
            break;
        }
        int vecValue = sudokuBoard[x][y]->hypVector[s]; //Vector value of checking cell
        bool row = true;
        bool col = true;
        bool box = true;
        for(int l=0; l<8; l++){
            std::vector<int> unitVector = sudokuRow(sudokuBoard, x, y)[l]->hypVector;   //Retreiveing vector of peer cell in row
            if (std::find(unitVector.begin(), unitVector.end(), vecValue) != unitVector.end()){     //Check if value in hypVector of unit cells
                row = false;
            }
            unitVector = sudokuCol(sudokuBoard, x, y)[l]->hypVector;   //Retreiveing vector of peer cell in col
            if (std::find(unitVector.begin(), unitVector.end(), vecValue) != unitVector.end()){     //Check if value in hypVector of unit cells
                col = false;
            }
            unitVector = sudokuBox(sudokuBoard, x, y)[l]->hypVector;   //Retreiveing vector of peer cell in box
            if (std::find(unitVector.begin(), unitVector.end(), vecValue) != unitVector.end()){     //Check if value in hypVector of unit cells
                box = false;
            }
        }
        if((row || col || box)){
            sudokuBoard[x][y]->setCell(vecValue);
            peer(sudokuBoard, x, y);
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    if(!sudokuBoard[i][j]->isSet()){
                        uniqueCandidate(sudokuBoard, i, j);
                    }
                }
            }
        }
        
    } 
};

int main(){     
//5...8..49...5...3..673....115..........2.8..........187....415..3...2...49..5...3
//4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
    std::string sudokuInput = "5...8..49...5...3..673....115..........2.8..........187....415..3...2...49..5...3";
    printInitialState(sudokuInput);
    sudokuSolver(sudokuInput);
    
    return 0;
    
}