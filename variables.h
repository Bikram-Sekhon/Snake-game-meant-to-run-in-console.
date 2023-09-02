#ifndef VARIABLES_H
#define VARIABLES_H
/*all of the vairables that are required to be accessible throughout 
different files of this game have been made made "extern" and defined
in the variables.cpp.*/
extern int width, height, snakePositionX, snakePositionY, snakeLength,
fruitX, fruitY;
extern bool gameOver;
extern char input, movement, snakeBody;
/*function required to print the struct object in the gamelogic.cpp, and is required
to be accessible in gameLayout.cpp, that is why it has been made exter. */
extern void snakePrint(int &i, int& j);
#endif