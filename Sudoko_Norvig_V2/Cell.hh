#ifndef CELL_HH_
#define CELL_HH_


class Cell
{
private:
    int value;
    bool isSet = false;
    int row;
    int col;
    int hypArray[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
public:
    Cell(int row, int col);
    Cell(int value);
    int getValue();
    bool getState();
    int getRow();
    int getCol();
    void setCell(int value);
    void removeFromHyp(int a);
    void printCell();
    void printHyp();
    int getHyp(int i);

    ~Cell();
};






#endif /* CAT_H_ */