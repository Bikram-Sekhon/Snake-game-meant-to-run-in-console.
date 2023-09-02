#include "systemsetup.h"
#include<math.h>
void systemSetup(){
    
    width =40;
    height =40;
    gameOver = false;
    snakePositionX= width/2;
    snakePositionY = height/2;
    fruitX= (width/2);
    fruitY = (height/4);
    input = 'a';
    movement = input;
    snakeLength = 0;
    snakeBody = 'o';
};