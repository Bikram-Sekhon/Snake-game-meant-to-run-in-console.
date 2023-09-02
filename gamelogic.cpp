#include "gamelogic.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
/*Since our whole game including snake and furit,  is printed x=1, y=1 to x=width, and y=height,
so we have to keep a track of the coordinates of the snake body, and as snake moves these coordinates have
to be updated for whole body at every step. 
a struct is the best way to store coordinates. We have created a struct by name snakeLocationCord with
two variables x and y. */
struct snakeLocationCord{
    int x{width/2};
    int y{height/2};
};
/*A struct array by the name "arr" of size 400 to store the struct objects. 
The length of the  coordinates has been set as 400 because our game window is 20x20=  400
block. So this array has to be big enough to store coordinates of each point of the game window, in case snake
grows that big. */
snakeLocationCord arr[400];
/*struct objec, whose instances will be stored in the arr[400] for each location*/
snakeLocationCord snake;
/*snakeLengthFunc() function is responsible for updating the array*/
void snakeLengthfunc(){
            if(snakePositionX == fruitX && snakePositionY == fruitY){
                snakeLength++;
            };
        
};
int lengthIndex;
void snakeLocation(){
    int tempHold{1};
    /*This if statement checks if snake has eaten fruit, and it is done by comparing if snake's head 
    co-ordinates 'snakePositionX' & 'snakePositionY' are equal to the furit coordinates 
    'furitX'& 'furitY', and if this condition is true then snake's body grows by one towards its tail. 
    To do this the length of the array that is responsible for storing the 'structs' of the snake body 
    coordinates, is increased by one throught the int variable "snakeLenght", and the newly accessed
    block of the array "arr[]" at index = snakeLength is made the head of the snake, and its coordinates
    are set equal to that of the coords of the fruit. It may be noted that this function has one "if"
    statement and one "else" statement. The if statement runs when snake eats fruit, and its length is to be
    increased by one. And the "else" statement runs when snake makes move without ecountering fruit. More description
    of how movement is updated in array is below right above the else statement. 
    This function also calls fruitLocation() function. Since fruit has been eated, during next step
    new fruit has to be generated at new location, this is done by calling function fruitLocation()
    immediately after the fruit is eaten. But note that it is called after updating the position of the
    snakes head, because it has to be updated equal to the position where fruit was, and if fruitLocation
    update function is called before updating the position of the head, then position of the head will
    become equal to the new location of the fruit, which would be a bug. */
    if(snakePositionX == fruitX && snakePositionY == fruitY){
        snakeLength++;
        arr[snakeLength].x = fruitX; arr[snakeLength].y = fruitY;
        // for(int i{snakeLength-1}; i>=0; i--){
        //     arr[i] = arr[i-1];
        // };
        lengthIndex = snakeLength;
        fruitLocation();
    }else {
    /*This for loop runs as many times as the lenght of the snake, and it 
    updates the position of the snake at every movement. 
    How does snake moves? Say its head moved from point X=20 & y=20 to X=21 & y=21, then
    the part of the body immediately behind the head should move to the position where head was
    located last time i.e. X=20 & Y=20. This is done as per below:
    The struct objectat index =1, is copied at index = 0, and struct object at index = 2 is 
    copied at index 1, and so on till struct object at index = snakeLength is copied at 
    index = snakeLength-1. Thereafter, as the for loop ends, the coordinates of the index = snakeLength
    are made equal to the position of the snakes head, i.e. snakePositionX and snakePositionY.
    at  block of arr[] at index = snakeLength stores the */
    for(tempHold; tempHold<=snakeLength;tempHold++){
    arr[tempHold-1] = arr[tempHold];
    };
    snake.x = snakePositionX; snake.y = snakePositionY;
    arr[snakeLength] =snake;
};
    snakeCutSelf();
};

//Prints fruitLocation:
void fruitLocation(){
   /*in order to check fruit is not printed on the snake body a "for" loop is run for the lenght of the snake
   and using a "while" loop it is checked that fruit is not on any location where there is any part of the body of the snake
   . The "for" loop runs through whole snake body Array for each X&Y coordinate, and the while loop runs as long as fruit's location is
   on some XY coordinate where snakes body is at that moment.*/
    for(int k{0};k<=snakeLength; k++){   
    while((fruitX==arr[k].x && fruitY == arr[k].y)
    ||(fruitX==1||fruitY==1||fruitX==0||fruitY==0)){
        fruitX= rand()%(width-1);
        fruitY = rand()%(height-1);
    };
    };
        

};
/*snakeMovement() function is responsible for receiving the input from the keyboard.
In this function the first conditional "if" checks if a valid key 'a', 's', 'w' or 'd' is pressed. Since
snake shouldn't be able to move 180 degrees of its current position, a switch statement compares if 
the input is not something 180 degrees opposite to the previous input, and if thats the case or the input
is other than the four options above,  then the movement remains the same as the previous input, so that 
snake moves next step in the direction in which it was moving before the key was pressed.  
thereafter checking if valid key is pressed.  */
void snakeMovement(){
    input = getch();
    if(((input =='a')||(input=='s'))||((input=='w'||input=='d'))){
        switch(input){
            case 'a':{if(movement!= 'd'){
                movement = input;
            }};break;
            case 's':{if(movement!='w'){
                movement = input;
            }};break;
            case 'w':{if(movement!='s'){
                movement = input;
            }}; break;
            case 'd':{if(movement!='a'){
                movement = input;
            }};break;
        };
    }
       /*This if, else if chain changes the location of the snake's head. Note: the snakePositionX &
       snakePositionY store the x and y coordinates of the head of the snake.*/
        if(movement == 'a'){snakePositionX--;}
        else if(movement == 'd'){snakePositionX++;}
        else if(movement == 'w'){snakePositionY--;}
        else if (movement == 's'){snakePositionY++;};
        
        /*This if statement checks if snake has */
        if(snakePositionX ==1||snakePositionX == width||snakePositionY ==1||snakePositionY == height)
        {
            gameOver = true;
        };
        
        
};
void snakeCutSelf(){
    for(size_t i{0}; i<snakeLength; i++){
        if(arr[i].x == snakePositionX && arr[i].y == snakePositionY){
            gameOver = true;
        }
    }
};


void testFunction(){
    std::cout<<"fruitX::"<<fruitX<<"  fruitY::"<<fruitY<<std::endl;
    if(lengthIndex == 0){
        std::cout<<"Index::"<<lengthIndex<<"::::X:::::"<<arr[lengthIndex].x
        <<":::::Y:::::"<<arr[lengthIndex].y<<std::endl;
    }
    else{while(lengthIndex >= 0){
        std::cout<<"Index::"<<lengthIndex<<"::::X:::::"<<arr[lengthIndex].x
        <<":::::Y:::::"<<arr[lengthIndex].y<<std::endl;
        lengthIndex--;

    };}
    lengthIndex = snakeLength;
    
};
/*Since wer are using a struct objecs to store coordinates of the snake body in
a struct array, and the body can only be printed by accessing the struct array arr[]. 
Printing of our game on console is done by gameLayout() function is gameLayout.cpp. However, 
this struct object array can not be accessed in other translation unit, i.e. in the functions 
internal to the other translation units. So we have defied the snakePrint function as 
extern in the variables.h and fed it with references to int i and int j of loops in 
"gameLayout()" function. This functions prints the body and head of the snake as well as empty space. 
and is called in the "gameLayout()" function. 
it runs as for loop for the lenght of the snake, and in this for loop there is an if statement, two else
if.
We want to print the body of the snake with 'o' and its head with "X". The first if statement checks if 
there is any struct object in the array that has same coordinates as the value of the "i" and "j", 
if there is any it prints 'o', next else if statement checks if the value of i = snake.x and 
j = snake.y at indext = length of the snake", if is true, it prints X as the head of the snake. 
if none of the above two loop is true, then it prints empty space. 
*/
void snakePrint(int &i, int& j){
for(int k{0};k<=snakeLength; k++){
    if(k<=(snakeLength -1)&&(i==arr[k].x) && (j == arr[k].y)){
        std::cout<<snakeBody;
        break;
    }else if((k==snakeLength)&&(i==arr[k].x && j == arr[k].y)){std::cout<<"X";break;} else if(k==snakeLength){std::cout<<" ";}
};

};

