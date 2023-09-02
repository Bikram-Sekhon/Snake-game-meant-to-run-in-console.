

#include "gamelogic.h"
#include "gamelayout.h"
#include<iostream>
#include<windows.h>
#include<stdlib.h>
/*gameLayout() function prints everyting that appears on the console of game.*/
void gameLayout(){
    /*This if statement checks if game is over, if its true, then it makes snakeBody
    char variable = '*' because we want the snake to look like a skeleton when game is over.
    */
    if(gameOver){
        snakeBody = '*';
    }
    /*clears the console everytime this function is called in while(!gameOver) loop 
    in the gameRunning() function in main.cpp.*/
    system("cls");
    /*this for loop prints the top line of the game borders in the console.*/
    for (size_t i =1; i<=width; i++){
        std::cout<<'#';
    };
    std::cout<<std::endl;
    /*this for loop prints the vertical borders of the game in console, as well as
    the snake body, fruit, and empty spaces within the four borders.*/
    for(int j = 2; j<= height-1; j++){
        for (int i =1; i<=width; i++){
        if((i==1)||(i==width)){
            std::cout<<'#';}else if((i==fruitX) && (j == fruitY)){std::cout<<'F';}
         else{snakePrint (i, j);};
    };
    std::cout<<std::endl;
    };
    /* this for loop prints the bottom line of the game borders in the console.*/
    for (size_t i =1; i<=width; i++){
        std::cout<<'#';
    };
   

};

