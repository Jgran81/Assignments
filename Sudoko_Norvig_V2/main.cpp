#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include <set>
#include "Cell.hh"

const int row = 9;
const int col = 9;

void sudokuSolver(std::string s);
void printInitialState(std::string s);
std::vector<Cell*>sudokuRow(Cell *sudokuBoard[row][col], const int x, const int y);
std::vector<Cell*>sudokuCol(Cell *sudokuBoard[row][col], const int x, const int y);
std::vector<Cell*>sudokuBox(Cell *sudokuBoard[row][col], const int x, const int y);
void removeFromPeers(Cell *sudokuBoard[row][col], const int x, const int y);
void uniqueCandidate(Cell *sudokuBoard[row][col], const int x, const int y);
void printHypoState(Cell *sudokuBoard[row][col]);
void printAfterSecondRule(Cell *sudokuBoard[row][col]);
bool isHypInRow(Cell *sudokuBoard[row][col], const int x, const int y, const int &_v);
bool isHypInCol(Cell *sudokuBoard[row][col], const int x, const int y, const int &_v);
bool isHypInBox(Cell *sudokuBoard[row][col], const int x, const int y, const int &_v);

//1. If a square has only one possible value, then eliminate that value from the square’s peers.
//2. If a unit has only one possible place for a value, then put the value there.


//ToDo_1 : Reduce the number of loops
void sudokuSolver(const std::string s){
    char letter;
    int num;
    std::vector<int> vec;
    for(int i=0; i<s.size(); i++){
        if (s[i] != '.'){
            letter = s[i];
            num = std::stoi(&letter);
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
                    removeFromPeers(sudokuBoard, i, j);
                }

            
            v++; 
        }
    }
    printHypoState(sudokuBoard);
    /* std::cout << std::endl;

    int _v = 1;

    bool val = isHypInRow(sudokuBoard, 3, 2, _v); */
    
    
    
    //std::set<int> test = isHypInRow(sudokuBoard, 3, 2);
    
    

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!sudokuBoard[i][j]->isSet()){
                uniqueCandidate(sudokuBoard, i, j);
            }
        }
    } 

    //isHypInRow(sudokuBoard, 3, 2);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!sudokuBoard[i][j]->isSet()){
                uniqueCandidate(sudokuBoard, i, j);
            }
        }
    } 

    printAfterSecondRule(sudokuBoard); 
    //printHypoState(sudokuBoard);
     
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
                if (j == 2 || j == 5){
                    std::cout << " | ";
                }
            }
            
            else{
                sudokuBoard[i][j]->printHyp();
                if (j == 2 || j == 5){
                    std::cout << " | ";
                }
            }
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::endl;
}

void printInitialState(const std::string s){

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
//bring in cell if it is not set.
std::vector<Cell*>sudokuRow(Cell *sudokuBoard[row][col], const int x, const int y){
    
    std::vector<Cell*>rowList;
    for(int i=0; i<9; i++){
        if(y != i && !sudokuBoard[x][i]->isSet()){  
            rowList.push_back(sudokuBoard[x][i]);
        }
    }
    //Size will be 8
    return rowList;
}
//Returns vector with pointers to column cells
std::vector<Cell*>sudokuCol(Cell *sudokuBoard[row][col], const int x, const int y){

    std::vector<Cell*>colList;

    for(int i=0; i<9; i++){
        if(x != i && !sudokuBoard[i][y]->isSet()){
            colList.push_back(sudokuBoard[i][y]);
        }
    }
    //Size will be 8
    return colList;
}
//Returns vector with pointers to box cells
std::vector<Cell*>sudokuBox(Cell *sudokuBoard[row][col], const int x, const int y){

    std::vector<Cell*>boxList;

    int startRow = x - x %3;    //Set box in row
    int startCol = y - y %3;    //Set box in col
    for(int i=startRow; i<(startRow+3); i++){  
        
        for(int j=startCol; j<(startCol+3); j++){
            if(sudokuBoard[x][y] != sudokuBoard[i][j] && !sudokuBoard[i][j]->isSet()){
                boxList.push_back(sudokuBoard[i][j]);
            }
        }
    }
    //Size will be 8
    return boxList;
}
bool isHypInRow(Cell *sudokuBoard[row][col], const int x, const int y, const int &_v){
    //1. loop through rowPeers
    //2. add vector number to set
    //3. check if value in set => return true else return false

    
    bool res = true;
    std::vector<int> cellVector;
    const int loopSize = sudokuRow(sudokuBoard, x, y).size();
    for (int i=0; i<loopSize; i++ ){
        if (!sudokuRow(sudokuBoard, x, y)[i]->isSet()){
            cellVector = sudokuRow(sudokuBoard, x, y)[i]->hypVector;
            if (std::find(cellVector.begin(), cellVector.end(), _v) != cellVector.end()){
                res = false;
                break;
            }
        }
    }
    return res;
}

bool isHypInCol(Cell *sudokuBoard[row][col], const int x, const int y, const int &_v){

    bool res = true;
    std::vector<int> cellVector;
    const int loopSize = sudokuCol(sudokuBoard, x, y).size();
    for (int i=0; i<loopSize; i++ ){
        if (!sudokuCol(sudokuBoard, x, y)[i]->isSet()){
            cellVector = sudokuCol(sudokuBoard, x, y)[i]->hypVector;
            if (std::find(cellVector.begin(), cellVector.end(), _v) != cellVector.end()){
                res = false;
                break;
            }
        }
    }
    return res;
}
bool isHypInBox(Cell *sudokuBoard[row][col], const int x, const int y, const int &_v){
    bool res = true;
    std::vector<int> cellVector;
    const int loopSize = sudokuBox(sudokuBoard, x, y).size();
    for (int i=0; i<loopSize; i++ ){
        if (!sudokuBox(sudokuBoard, x, y)[i]->isSet()){
            cellVector = sudokuBox(sudokuBoard, x, y)[i]->hypVector;
            if (std::find(cellVector.begin(), cellVector.end(), _v) != cellVector.end()){
                res = false;
                break;
            }
        }
    }
    return res;

}

void removeFromPeers(Cell *sudokuBoard[row][col], const int x, const int y){ 

    std::vector<Cell*>rowList = sudokuRow(sudokuBoard, x, y);
    std::vector<Cell*>colList = sudokuCol(sudokuBoard, x, y);
    std::vector<Cell*>boxList = sudokuBox(sudokuBoard, x, y);
    //vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
    std::vector<Cell*>peerVector;
    peerVector.insert(peerVector.end(), rowList.begin(), rowList.end());
    peerVector.insert(peerVector.end(), colList.begin(), colList.end());
    peerVector.insert(peerVector.end(), boxList.begin(), boxList.end());
    std::set<Cell*> s(peerVector.begin(), peerVector.end());
    peerVector.clear();
    peerVector.insert(peerVector.end(), s.begin(), s.end()); 
    //if (std::find(hypVector.begin(), hypVector.end(), a) != hypVector.end()){
    for (auto i=0; i<peerVector.size(); i++){
        //if (std::find(peerVector[i]->hypVector.begin(), peerVector[i]->hypVector.end(), sudokuBoard[x][y]->getValue()) != peerVector[i]->hypVector.end()){}
        peerVector[i]->removeFromHyp(sudokuBoard[x][y]->getValue());
        if (peerVector[i]->isSet()){
            removeFromPeers(sudokuBoard, peerVector[i]->getRow(), peerVector[i]->getCol());
            peerVector.erase(std::remove(peerVector.begin(), peerVector.end(), peerVector[i]), peerVector.end());
        }
    } 
    /* for (auto i=0; i<peerVector.size(); i++){
        uniqueCandidate(sudokuBoard, peerVector[i]->getRow(), peerVector[i]->getCol());
        if (peerVector[i]->isSet()){
            removeFromPeers(sudokuBoard, peerVector[i]->getRow(), peerVector[i]->getCol());
            peerVector.erase(std::remove(peerVector.begin(), peerVector.end(), peerVector[i]), peerVector.end());
        }
    } */
    //Can I add the rowList, colList and boxList in one ?
    //Get rowList and remove hypothetical values from cells in that list
    
    /* for(auto i=0; i<rowList.size(); i++){
        if(!rowList[i]->isSet()){   //Checks if cell already set
            rowList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());   //Removes from hypothetical array
            if(rowList[i]->isSet()){         //If value gets assigned
                removeFromPeers(sudokuBoard, rowList[i]->getRow(), rowList[i]->getCol());  //Recursion if value gets set
            }
            else {uniqueCandidate(sudokuBoard, rowList[i]->getRow(), rowList[i]->getCol());}
        }
        
    }
    
    //Get colList and remove hypothetical values from cells in that list
    
    for(auto i=0; i<colList.size(); i++){
        if(!colList[i]->isSet()){    //Checks if cell already set
            colList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());   //Removes from hypothetical array
            if(colList[i]->isSet()){
                removeFromPeers(sudokuBoard, colList[i]->getRow(), colList[i]->getCol());
            }
            else {uniqueCandidate(sudokuBoard, colList[i]->getRow(), colList[i]->getCol());}
        }
    }
    
    //Get cboxList and remove hypothetical values from cells in that list
    
    for(auto i=0; i<boxList.size(); i++){
        if(!boxList[i]->isSet()){
            boxList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());
            if(boxList[i]->isSet()){
                removeFromPeers(sudokuBoard, boxList[i]->getRow(), boxList[i]->getCol());
            }
            else {uniqueCandidate(sudokuBoard, boxList[i]->getRow(), boxList[i]->getCol());}
        }        
    } */
}


void uniqueCandidate(Cell *sudokuBoard[row][col], const int x, const int y){

    int vecSize = sudokuBoard[x][y]->hypVector.size(); //size of vector
    
    for(auto s=0; s<vecSize; s++){
        if (sudokuBoard[x][y]->isSet()){
            break;
        }
        int vecValue = sudokuBoard[x][y]->hypVector[s]; //Vector value of checking cell
        bool row = isHypInRow(sudokuBoard, x, y, vecValue);
        bool col = isHypInCol(sudokuBoard, x, y, vecValue);
        bool box = isHypInBox(sudokuBoard, x, y, vecValue);
        
        if((row || col || box)){
            sudokuBoard[x][y]->setCell(vecValue);
            removeFromPeers(sudokuBoard, x, y);
            /* for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    if(!sudokuBoard[i][j]->isSet()){
                        uniqueCandidate(sudokuBoard, i, j);
                    }
                }
            } */
        }
    } 
}

int main(){     
//5...8..49...5...3..673....115..........2.8..........187....415..3...2...49..5...3
//4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
//..............3.85..1.2.......5.7.....4...1...9.......5......73..2.1........4...9
    std::string sudokuInput = "..............3.85..1.2.......5.7.....4...1...9.......5......73..2.1........4...9";
    printInitialState(sudokuInput);
    sudokuSolver(sudokuInput);
    
    return 0;
    
}