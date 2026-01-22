#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs* gmPtr;
Player* playerPtr;
Food* foodPtr;




int main(void)
{

    Initialize();

    while(gmPtr->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    srand(time(NULL)); //seed random generator to improve randomness

    MacUILib_init();
    MacUILib_clearScreen();

    //exitFlag = false, becasue when we call the default constructor of GameMechs, exitFlag is already false

    //initializing pointers
    gmPtr = new GameMechs();
    foodPtr = new Food(gmPtr);
    playerPtr = new Player(gmPtr, foodPtr);

    
    objPosArrayList blockOffList;          // make a list container
    playerPtr->getPlayerPos(blockOffList);  //copy player list into it
    foodPtr->generateFood(blockOffList);  //generate food safely

}

void GetInput(void)
{
    if (MacUILib_hasChar()){ //checks whether there is input and the calls on the setInput function in game Mechs to use it
        gmPtr->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{

    if (gmPtr->getInput() == 27) { //exit key is 'esc'
        gmPtr->setExitTrue();
        gmPtr->clearInput();
    }

    playerPtr->updatePlayerDir();
    playerPtr->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    //Get board size from game Mechs and set those into the row and column variables 
    int COL = gmPtr->getBoardSizeX(); 
    int ROW = gmPtr->getBoardSizeY();

    char board[ROW][COL]; //creates an array of ROW X COL size

    for(int i = 0; i < ROW; i++){
        for(int j = 0 ; j < COL; j++){
    
            if((i == 0) || (j == 0) || (i== ROW - 1)||(j == COL - 1)){ //prints outside border of #
                board[i][j] = '#';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }  

    //draw food
    objPosArrayList F;
    foodPtr->getBucketPos(F);

    for(int i = 0; i < F.getSize(); i++){
        objPos food = F.getElement(i);
        board[food.getY()][food.getX()] = food.getSymbol();
    }

    //get position of player 
    objPosArrayList p; //make a list container
    playerPtr->getPlayerPos(p); // copy player list into it

    //Place player on board
    for(int i = 0; i < p.getSize(); i++) { //check size of player list
        objPos part = p.getElement(i); //extract each element
        board[part.getY()][part.getX()] = part.getSymbol(); //prints each element on board
    }

    // Print the board
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            MacUILib_printf("%c", board[i][j]);
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", gmPtr->getScore());
    MacUILib_printf("\n");
    MacUILib_printf("Features: \n");
    MacUILib_printf("o increases length and score by 1\n");
    MacUILib_printf("$ increases score by 10 and length by nothing\n");
    MacUILib_printf("\n");
    MacUILib_printf("Press 'ESC' to exit the Game!\n");
    

}


void LoopDelay(void)
{
    MacUILib_Delay(100000); // 0.1s delay
}


void CleanUp(void)
{
    
    MacUILib_clearScreen(); 

    // Final Print statement after clear screen based off of lose flag
    if(gmPtr->getLoseFlagStatus() == true){
        MacUILib_printf("\n==================\n");
        MacUILib_printf("You lost the game!\n");
        MacUILib_printf("==================\n");
    }
    else{
        MacUILib_printf("\n======================\n");
        MacUILib_printf("Thank you for playing!\n");
        MacUILib_printf("======================\n");
    }
    //deallocate memory space
    delete gmPtr;
    delete playerPtr;
    delete foodPtr;  

    MacUILib_uninit();
}
