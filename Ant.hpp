

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"
class Board;

using namespace std;

class Ant {   
private:
    int steps;  // steps to take
    int row, col;   // holds current location of ant 
    Board *board;
    enum Direction { NORTH, SOUTH, EAST, WEST }; 
    Direction facing;
    //int direction[4] = {0, 1, 2, 3};    // 0 = NORTH, 1 = EAST, 3 = SOUTH, 4 = WEST
    bool collision();
    void stepForward();
    
public:
    Ant(int, int, int, Board *currentBoard);
    void move();
    /*int getX();
    int getY();*/
    
    
};

#endif /* ANT_HPP */

