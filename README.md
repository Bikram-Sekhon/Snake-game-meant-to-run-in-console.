# Snake-game-meant-to-run-in-console.
The flow of the code of this game is as per below:
1.  This game has four main blocks:
2.  Printing everthing on screen. Everthing includes, the top, bottom, and both side borders of the game
    fruit, snake, and empty spaces where none of these object exist.
    The borders are printed using for loops.
    And for the purpose of printing the space within the borders, involves checking if there
    is either fruit or any body part of the snake correspond to the XY location of every coordinate.
    If neither of these is there, then empty space is printed. 
4.  In the game logic part, the first even is snake movement.
    Moving snake on the basis of player input, checks if valid key is pressed, if snake encounters fruit in this movement,
    whether it hits the wall or its own body.
    If it encounters the fruit, its length is increased by one and fruit is generated at new location. 
6.  After checking all these conditions and after finding them valid, console is cleared and everthing mentioned in point 2 above
    is prinited on the console.
    Thereafter, again step 4 is performed, and it goes on till game over conditions are fullfilled, which triggers
    the functions that displays score and asks the player if they want to replay or exit, and proceeds accrodingly. 
Note: this code uses the concept of structures to store the coordinates of the snake body. 
