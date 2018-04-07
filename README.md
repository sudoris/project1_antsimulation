Description:
Implementation of a simulation of Langton's Ant - read more on Wikipedia --> https://en.wikipedia.org/wiki/Langton%27s_ant

Author: 
David Chen

What the program does:
-A simple menu allows the user to choose 1 to run the simulation, and 2 to quit the program.
-If 1 is chosen, the user is asked to choose the size of the board (no greater than 80x80 and no less than 2x2).
-User is asked to choose the row and column for the ant's starting position.
-User is asked to enter the number of steps to have the ant move.

Rules for movement during simulation -
1. When on a white square, turn right 90 degrees and change the square to black.
2. When on black square, turn left 90 degrees and change the square to white.

The ant is represented by a @ char. Black squares are represented by #. White squares are represented by ' '.

For wall collision cases (i.e. ant attempts to step out of bounds of the array), the ant turns around before making its move.





