#include<iostream>
#include "gamelayout.h"
#include "systemsetup.h"
#include "gamelogic.h"
#include<windows.h>
//function to prevent the cursor from appearing on console window, which makes game look smooth.
void ShowConsoleCurson(bool showFlag){
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag;
        SetConsoleCursorInfo(out, &cursorInfo);
    };
    /*gameRunning() function has all the functions nested inside that make the game run. 
    and all these functions run inside a while loop, whose condition of gameOver is by default
    set to false, and when it becomes true whether by snake hitting the wall or itsef, 
    it become true, and game stops and control moves to if statement, which prints the 
    snake in gameover condition, and asks if player want to replay or quit. If player opts to replay
     it runs systemSetup() function which resets all the variables to preset defaults along with
    setting bool gameOver = false, making the while loop run again.. */
void gameRunning(){
     
    while(!gameOver){
        ShowConsoleCurson(false);
        gameLayout(); 
        snakeMovement();
        snakeLocation();

        if (gameOver){
        gameLayout();
        std::cout<<std::endl;
        std::cout<<"Oops!! Game Over"<<std::endl;
        std::cout<<"Your score is "<<snakeLength*200<<std::endl;
        char replayOption;
        std::cout<<"Press 'R' and hit enter to reply "<<std::endl
        <<"If want to quit press 'Q' and hit enter  "<<std::endl;
        std::cin>>replayOption;
        if(replayOption == 'r'|| replayOption == 'R'){
           gameOver = false;
           systemSetup();};
           if(replayOption == 'q'|| replayOption == 'Q'){
            exit;
           };
           std::cout<<std::endl<<std::endl;   };
        Sleep(20);  };
};
int main(){
    ShowConsoleCurson(false);
    gameRunning();  
    
    return 0;
};