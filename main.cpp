
#include "Board.hpp"
#include "Ant.hpp"
//#include <cstdlib>
#include <iostream>

using namespace std;

void menu() {
    int option;  
    int size = 0;
    int row, column; 
    int numberOfSteps;
    char **squareBoard;
        
    while (true) {
                
        cout << "1) Start simulation" << endl ;
        cout << "2) End " << endl;
        
        cin >> option;
        
        if (option == 2) {
            break;
        } 	    
     	else if (option == 1) {    // run simulation if 1 is chosen
            cout << "Enter size for board (min: 2, max 80): ";
            cin >> size; 
            while (size < 2 || size > 80) {
                cin.clear();                    //clear flag for invalid input
                cin.ignore(256, '\n');          //clear input in cin
                cout << "Invalid size entered, please enter a number between 1~80." << endl;
                cout << "Enter size for board (min: 2, max 80): ";
                cin >> size; 
            }            
            cout << "Enter row to start in (must be an integer no greater than size of board): ";
            cin >> row;
            while (row < 1 || row > size) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid row entered." << endl;
                cout << "Enter row to start in (must be an integer no greater than size of board): ";
                cin >> row; 
            }    
            cout << "Enter starting column: ";
            cin >> column;
            while (column < 1 || column > size) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid column entered." << endl;
                cout << "Enter column to start in (must be an integer no greater than size of board): ";
                cin >> column; 
            }
            cout << "Enter number of steps for ant to take (must be an integer no greater than 10,000): ";
            cin >> numberOfSteps;
            while (numberOfSteps < 1 || numberOfSteps > 10,000) {   
                cin.clear();
                cin.ignore(256, '\n');                
                cout << "Invalid number entered." << endl;
                cout << "Enter number of steps for ant to take (must be an integer no greater than 10,000): ";
                cin >> numberOfSteps; 
            } 
            
            squareBoard = new char* [size];    //allocate space for 1st row of array
            for (int row = 0; row < size; row++) {
                squareBoard[row] = new char[size];             //allocate space for columns of array
            }  
            
            Board board1(squareBoard, size);
            board1.initializeBoard();
            Ant anAnt(row, column, numberOfSteps, &board1);
            anAnt.move();
            
            for (int row = 0; row < size; row++) {
                delete[] squareBoard[row];
            }
            delete [] squareBoard;
            
            //did not need to delete objects created due to scope 
        } 
		
                                         
                          
    }
}



int main() {
    
    menu();   	       //start program  
    
      
    return 0;
}


