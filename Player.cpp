#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef; //obtains a reference of the GameMechs that specifies key elements for the game like boardsize and score.
    this->foodRef = foodRef;  // obtain a reference of the food object, so we are able to then compare positions 
    myDir = STOP;  

    // Initial coordinates of head
    int X = mainGameMechsRef->getBoardSizeX() / 2; 
    int Y = mainGameMechsRef->getBoardSizeY() / 2;

    playerPosList = new objPosArrayList();

    //Initialization of list, can change the symbol to whatever here
    playerPosList->insertHead(objPos(X, Y, '*'));

    // playerPosList->insertTail(objPos(X-1, Y, '*'));
    // playerPosList->insertTail(objPos(X-2, Y, '*'));
    // playerPosList->insertTail(objPos(X-3, Y, '*'));

}

Player::~Player() { //destructor, memory saver
    delete playerPosList;
    playerPosList = nullptr;
}

void Player::getPlayerPos(objPosArrayList &returnPos) const //takes the list passed in, and overwrites it with a deep copy of everything inside PlayerPosList
{
    
    returnPos = *playerPosList;

}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); //collects the input key pressed

    if(input != 0)
    {
        switch(input) //
        {
            case 'w': case 'W': //Can only move up, if it wasn't previously moving down when w/W is pressed
                if(myDir != DOWN)
                    {myDir = UP;}
                    break;

            case 's': case 'S': //Can only move down, if it wasn't previously moving up when s/S is pressed
                if(myDir != UP) 
                    {myDir = DOWN;}
                    break;

            case 'a': case 'A': //Can only move left, if it wasn't previously moving right when a/A is pressed
                if(myDir != RIGHT) 
                    {myDir = LEFT;}
                    break;

            case 'd': case 'D': //Can only move right, if it wasn't previously moving left when d/D is pressed
                    if(myDir != LEFT) 
                    {myDir = RIGHT;}
                    break;
        }
    }

    mainGameMechsRef->clearInput(); //clears the input after processing
}

void Player::movePlayer()
{
    //Initial x and y coordinates
    int x = playerPosList->getHeadElement().getX();
    int y = playerPosList->getHeadElement().getY();

    //Board size
    int boardX = mainGameMechsRef->getBoardSizeX();
    int boardY = mainGameMechsRef->getBoardSizeY();

    // Boundaries of movement area
    int maxBoardX = boardX - 2;
    int maxBoardY = boardY - 2;

    char playerSmbol = playerPosList->getHeadElement().getSymbol();

    switch(myDir) //increments/decrements the position on the player based off the direction that the user input
    {
        case UP:    
            y--; 
            break;

        case DOWN:  
            y++; 
            break;

        case LEFT:  
            x--; 
            break;

        case RIGHT: 
            x++; 
            break;

        case STOP:  
            return;

        default: 
            return;
    }

    // wraparound like PPA3 scavenger
    if(x < 1) 
        {x = maxBoardX;}

    if(x > maxBoardX) 
        {x = 1;}

    if(y < 1) 
        {y = maxBoardY;}

    if(y > maxBoardY) 
        {y = 1;}

    
    objPosArrayList F; // To be able to access the food bucket
    foodRef->getBucketPos(F); // Pointer to the food bucket
    bool ateFood = false; // Initial state - hasnt consumed food yet
    char foodSym; // Holds current value of the symbol of food consumed

    // Iterate through length of food bucket (5)
    for(int i = 0; i < F.getSize(); i++){
        objPos food = F.getElement(i); // Get the values of each food element in bucket (x,y , symbol)

        if(x == food.getX() && y == food.getY()){
            ateFood = true;
            foodSym = food.getSymbol(); // Hold symbol of consumed food
            break;
        }
    }
    playerPosList->insertHead(objPos(x, y, playerSmbol)); 

 // If the snake overlapped with any food    
    if(ateFood){
        // Regular food consumption
        if(foodSym == 'o'){
            foodRef->generateFood(*playerPosList); //generate food safely
            mainGameMechsRef->incrementScore();    // Increments the score by 1
        }
        // Special food consumption
        else if(foodSym == '$'){
            foodRef->generateFood(*playerPosList);       //generate food safely
            mainGameMechsRef->incrementScoreSpecial();   // Increments the score by 10
            playerPosList->removeTail();                 // Does not increase the length of the snake (removes the tail)
        }
    }
    else{
        playerPosList->removeTail(); // Removes the tail 

    }

    // Iterate through each element of the snake
    for( int m = 1; m < playerPosList->getSize(); m++){

       // Iterate through each element in the list and compare to the head
        if(x == playerPosList->getElement(m).getX() && y == playerPosList->getElement(m).getY()){
            // Set lose flag and exit flag true
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

}

int Player::getX() const
{
    return playerPosList->getHeadElement().getX();
}

int Player::getY() const
{
    return playerPosList->getHeadElement().getY();
}

char Player::getSymbol() const
{
    return playerPosList->getHeadElement().getSymbol();
}

