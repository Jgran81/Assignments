#include <iostream>
#include <sstream>
#include <vector>
#include "Cell.hh"
const int row = 9;
const int col = 9;

//1. If a square has only one possible value, then eliminate that value from the square’s peers.
//2. If a unit has only one possible place for a value, then put the value there.


//Returns vector with pointers to row cells
std::vector<Cell*>sudokuRow(Cell *sudokuBoard[row][col], int x, int y){
    
    std::vector<Cell*>rowList;
    
    int listIt = 0;
    for(int i=0; i<9; i++){
        if(sudokuBoard[x][y] != sudokuBoard[x][i]){
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
        if(sudokuBoard[x][y] != sudokuBoard[i][y]){
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
    
    //1. Get cell
    //2. Get row, col and box
    //3. Remove hypo from each
    //4. Bonus assignment:
        //4.1 Merge vectors?
        //4.2 Function for remove from hypothetical

    //Get rowList and remove hypothetical values from cells in that list
    std::vector<Cell*>rowList = sudokuRow(sudokuBoard, x, y);
    for(int i=0; i<rowList.size(); i++){
        if(!rowList[i]->getState()){   //Checks if cell already set
            rowList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());   //Removes from hypothetical array
            if(rowList[i]->getState()){         //If value gets assigned
                peer(sudokuBoard, rowList[i]->getRow(), rowList[i]->getCol());  //Recursion if value gets set
            }
        }
        
    }
    
    //Get colList and remove hypothetical values from cells in that list
    std::vector<Cell*>colList = sudokuCol(sudokuBoard, x, y);
    for(int i=0; i<colList.size(); i++){
        if(!colList[i]->getState()){    //Checks if cell already set
            colList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());   //Removes from hypothetical array
            if(colList[i]->getState()){
                peer(sudokuBoard, colList[i]->getRow(), colList[i]->getCol());
            }
        }
    }
    
    //Get cboxList and remove hypothetical values from cells in that list
    std::vector<Cell*>boxList = sudokuBox(sudokuBoard, x, y);
    for(int i=0; i<boxList.size(); i++){
        if(!boxList[i]->getState()){
            boxList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());
            if(boxList[i]->getState()){
                peer(sudokuBoard, boxList[i]->getRow(), boxList[i]->getCol());
            }
        }
        
    }
    
    /* std::cout << std::endl;
    for(int i=0; i<20; i++){
        peerList[i]->removeFromHyp(sudokuBoard[x][y]->getValue());
    } */
};

void uniqueCandidate(Cell *sudokuBoard[row][col], int x, int y){
    //1. Iterate over sudokuBoard to find first non-set cell - outside in main()?
    //2. Check hypo list against other hypo lists
    //3. Checker set to true if no other hypo is detected and false if hypo is detected -> jump out of loop
    //4. If value can be set, run peer() again with that value.
    
    for(int k=0; k<9; k++){     //Iterate over hypArray. k is position in hypArr
        if(sudokuBoard[x][y]->getHyp(k)>0){     //Get the hypArray value
            for(int l=0; l<8; l++){             //l is position in unit vector
                if(sudokuRow(sudokuBoard, x, y)[l]->getHyp(k)>0 ||
                    sudokuCol(sudokuBoard, x, y)[l]->getHyp(k)>0 ||
                    sudokuBox(sudokuBoard, x, y)[l]->getHyp(k)>0){
                    //std::cout << "Cell is not set! " << std::endl;
                    break;
                }
                else if(l>6){
                    if(sudokuRow(sudokuBoard, x, y)[l]->getHyp(k)<1 ||
                        sudokuCol(sudokuBoard, x, y)[l]->getHyp(k)<1 ||
                        sudokuBox(sudokuBoard, x, y)[l]->getHyp(k)<1);   //Yesus I'm sorry...
                        sudokuBoard[x][y]->setCell(k+1);
                        break;
                        //std::cout << sudokuBoard[x][y]->getValue();
                        //std::cout << "Cell is set! " << std::endl;
                        
                }
            }
        }
    }
}

//ToDo: 1. Create an array of pointers to objects  -- Done!!! +1 beer
//ToDo: 2. Function for peer grouping. -- Done!!!- +1 beer
//ToDo: 3. Implement unique candidate. only cell with hypValue in line or col or box
//ToDo: 4. Unique functions for line, col and box? How to bring together to peerList? --Done! +1 beer
//ToDo: 5. Recursive call from peer function if value gets set --Done!!! +1 beer
int main(){     
//5...8..49...5...3..673....115..........2.8..........187....415..3...2...49..5...3
//4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
    std::string sudokuInput = "5...8..49...5...3..673....115..........2.8..........187....415..3...2...49..5...3";
    
    
    for(int i=0; i<81; i++){
        if(i%9 == 0){
            std::cout << std::endl;
        }
        if(i%3 == 0){
            std::cout << "| ";
        }
        std::cout << sudokuInput[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    Cell *sudokuBoard[row][col] = {};
    //Creating pointers to all objects in dynamic mem. 
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sudokuBoard[i][j] = new Cell(i, j);
        }
    }
    int v=0;
    int set;
    std::string input;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(sudokuInput[v] != '.'){
                input = sudokuInput[v];
                set = stoi(input);
                sudokuBoard[i][j]->setCell(set);
                peer(sudokuBoard, i, j);
                

            }
            v++; 
        }
    }
    sudokuBoard[7][2]->printHyp();
    std::cout << std::endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!sudokuBoard[i][j]->getState()){
                uniqueCandidate(sudokuBoard, i, j);
                //std::cout << "This " << i << " " << j << std::endl;
            }
        }
    }
    

    
    //Print hypothetical numbers
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sudokuBoard[i][j]->printCell();
        }
        std::cout << std::endl;
    } 

    /* for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            sudokuBoard[i][j]->printHyp();
        }
        std::cout << std::endl;
    } */
    
    //sudokuBoard[0][0]->printHyp();
    


    /* std::cout << "Plats [3][3]" <<sudokuBoard[3][3]->getValue() << std::endl; */
    //peer(sudokuBoard, 8, 8);
    
    //Return memory
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            delete sudokuBoard[i][j];
            sudokuBoard[i][j] = nullptr;
            
        }
    }
    return 0;
    
}