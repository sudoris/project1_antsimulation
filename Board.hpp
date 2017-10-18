
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

using namespace std;

class Board {
private:
    char **board;
    int boardSize;
    //Ant &anAnt;
        
public:
    Board(char**, int);
    void initializeBoard();
    void setSquare(int, int, char);
    void printBoard(int, int);
    int getSize(); 
    char getSquare(int, int);
   

    

};

#endif /* BOARD_HPP */

