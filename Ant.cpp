
#include "Ant.hpp"

Ant::Ant(int startingRow, int startingCol, int numberOfSteps, Board *currentBoard) {
    row = startingRow - 1;      // -1 since array starts at 0
    col = startingCol - 1;      // -1 since array starts at 0
    steps = numberOfSteps;
    board = currentBoard;
    facing = NORTH;
}

void Ant::move() {
    int counter = 0;
    while (counter <= steps) {    
        if (collision()) {           // if collision function returns true, turn ant around
            if (facing == NORTH) {                       
                facing = SOUTH;
            }
            else if (facing == SOUTH) {
                facing = NORTH;
            } 
            else if (facing == EAST) {
                facing = WEST;
            } 
            else {
                facing = EAST;
            }            
        }
        
        if ((*board).getSquare(row, col) == ' ') {   // have ant turn right if currently on a white square
            if (facing == NORTH) {
                facing = EAST;
            } 
            else if (facing == SOUTH) {
                facing = WEST;
            } 
            else if (facing == EAST) {
                facing = SOUTH;
            } 
            else {
                facing = NORTH;
            }               
            
            (*board).setSquare(row, col, '#');   // flip color of square before taking step forward
        }         
        else if ((*board).getSquare(row, col) == '#') { // have ant turn left if currently on black square
            if (facing == NORTH) {
                facing = WEST;
            } 
            else if (facing == SOUTH) {
                facing = EAST;
            }
            else if (facing == EAST) {
                facing = NORTH;
            } 
            else {
                facing = SOUTH;
            }     
            
            (*board).setSquare(row, col, ' ');    // flip color of square before taking step forward
            
        }
        
        (*board).printBoard(row, col);        
        stepForward();
        counter++;
    }
}

void Ant::stepForward() {    //move ant forward by one step
    if (facing == NORTH) {
        row-=1;
    } 
    else if (facing == SOUTH) {
        row+=1;
    } 
    else if (facing == EAST) {
        col+=1;
    } 
    else {
        col-=1;
    }
}

bool Ant::collision() {
	//note to self: try to combine similar if statements when I have time
    if ((*board).getSquare(row, col) == ' ') { // if ant is currently on white square
        if (row == 0 && col == 0 && facing == WEST ) {   // if top left corner facing WEST
            return true;
        }
        else if (row == 0 && col == 0 && facing == SOUTH ) {   // if top left corner facing SOUTH
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == 0 && facing == SOUTH) {  // if bottom left corner facing SOUTH
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == 0 && facing == EAST) {  // if bottom left corner facing EAST
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == ((*board).getSize() - 1) && facing == EAST) {   // if bottom right corner facing EAST
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == ((*board).getSize() - 1) && facing == NORTH) {   // if bottom right corner facing NORTH
            return true;
        }
        else if (row == 0 && col == ((*board).getSize() - 1) && facing == NORTH) {  // if top right corner facing NORTH
            return true;
        }
        else if (row == 0 && col == ((*board).getSize() - 1) && facing == WEST) {  // if top right corner facing WEST
            return true;
        }        
        else if (col == ((*board).getSize() - 1) && facing == NORTH) {    // if next to right border facing NORTH 
            return true;
        }
        else if (col == 0 && facing == SOUTH) {        // if next to left border facing SOUTH
            return true;
        }      
        else if (row == 0 && facing == WEST) {         // if along top border facing WEST
            return true;
        }
        else if (row == ((*board).getSize() - 1) && facing == EAST) {     // if along bottom border facing EAST
            return true;
        } 
    }
    
    if ((*board).getSquare(row, col) == '#') {
        if (row == 0 && col == 0 && facing == NORTH) {   // if top left corner facing NORTH
            return true;
        }
        else if (row == 0 && col == 0 && facing == EAST) {   // if top left corner facing EAST
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == 0 && facing == WEST) {  // if bottom left corner facing WEST
            return true;
        }
        else if (row == ((*board).getSize() - 1)  && col == 0 && facing == NORTH) {  // if bottom left corner facing NORTH
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == ((*board).getSize() - 1) && facing == SOUTH) {   // if bottom right corner facing SOUTH
            return true;
        }
        else if (row == ((*board).getSize() - 1) && col == ((*board).getSize() - 1) && facing == WEST) {   // if bottom right corner facing WEST
            return true;
        }
        else if (row == 0 && col == ((*board).getSize() - 1) && facing == EAST) {  // if top right corner facing EAST
            return true;
        }
        else if (row == 0 && col == ((*board).getSize() - 1) && facing == SOUTH) {  // if top right corner facing SOUTH
            return true;
        }       
        else if (col == ((*board).getSize() - 1) && facing == SOUTH) {    // if next to right border facing SOUTH
            return true;
        }
        else if (col == 0 && facing == NORTH) {        // if next to left border facing NORTH
            return true;
        }       
        else if (row == 0 && facing == EAST) {         // if along top border facing EAST
            return true;
        }
        else if (row == ((*board).getSize() - 1) && facing == WEST) {     // if along bottom border facing WEST
            return true;
        } 
    }
    
    return false;
}




