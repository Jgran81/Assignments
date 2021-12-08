#ifndef CELL_HH_
#define CELL_HH_


class Cell
{
public:
    int value;
    bool set = false;
    int row;
    int col;
    
    std::vector<int> hypVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
public:
    Cell(int row, int col);
    Cell(int value);
    int getValue();
    bool isSet();
    int getRow();
    int getCol();
    void setCell(int value);
    void removeFromHyp(int a);
    void printCell();
    void printHyp();

};






#endif /* CAT_H_ */