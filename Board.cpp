
#include "Board.hpp"
#include <iostream>

Board::Board(char** squareBoard, int size) {            
    boardSize = size;    
    board = squareBoard;      
}

void Board::initializeBoard() {         // set all elements of array to a blank space
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            board[row][column] = ' ';
        }
    }          
    
}

void Board::setSquare(int row, int col, char squareType) {
    board[row][col] = squareType;
}

void Board::printBoard(int rowAntOn, int colAntOn) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (i == rowAntOn&& j == colAntOn) {
                cout << '@' << " ";      // when printing square ant is currently on, print @ instead of # or " "
            } else {
                cout << board[i][j]; //<< " ";
            }
            
            
        }
        cout << endl;
    }
    
    /*for (int i = 1; i < boardSize; i++) {
        cout << "---" ;
       }*/
    cout << endl;
    //cout << endl;
    
}

char Board::getSquare(int row, int col) {        
    return board[row][col];
}

int Board::getSize() {
   return boardSize; 
}






