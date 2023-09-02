#include "variables.h"
#include<math.h>
int width =40;
int height =40;
bool gameOver = false;
int snakePositionX= width/2;
int snakePositionY = height/2;
int fruitX= rand()%(width-1);
int fruitY = rand()%(height-1);
char input = 'a';
char movement = input;
int snakeLength = 0;
char snakeBody = 'o';