#include "Food.h"
#include <iostream>
#include <time.h>


using namespace std;

Food::Food(GameMechs* thisGMRef) //creates a reference to 
{
    mainGameMechsRef = thisGMRef;
    foodBucket = new objPosArrayList();

}

Food::~Food() { 
    delete foodBucket;
    foodBucket = nullptr;
}

void Food::generateFood(const objPosArrayList &blockOffList)
{
    // Clear the food bucket each time this is called ( to generate new food)
    for(int i = 0 ; i < 5; i++){
    foodBucket->removeTail();
    }

    int X = mainGameMechsRef->getBoardSizeX();
    int Y = mainGameMechsRef->getBoardSizeY();

    int xRange, yRange;
    bool overlap;
    char foodSymbol = 'o';
    char specialFood = '$';
    int c = 0; // Keep track of special and regular food elements

    for(int i = 0; i < 5; i++){
    do {
        overlap = false;
        xRange = 1 + rand() % (X - 2);
        yRange = 1 + rand() % (Y - 2);

        // check against ALL snake segments 
        for(int j = 0; j < blockOffList.getSize(); j++)
        {
            if(xRange == blockOffList.getElement(j).getX() &&
               yRange == blockOffList.getElement(j).getY())
            {
                overlap = true;
                break;
            }
        }

        // Check against rest of food bucket items
        for(int k = 0; k < foodBucket->getSize(); k++){
            if(xRange == foodBucket->getElement(k).getX() && 
               yRange == foodBucket->getElement(k).getY())
               { 
                overlap = true;
                break;
               }
        }
    } while(overlap); // keep loping until a position that doesn't overlap is generated 

    // To create different symbols:
    if(c < 3){ //Three regular food elements on board
        foodPos.setObjPos(xRange, yRange, foodSymbol); 
        foodBucket->insertTail(foodPos); // Append to the food bucket
        c++;
    }
    else if(c >= 3 && c < 5){ // Last two elements are special food
        foodPos.setObjPos(xRange, yRange, specialFood); 
        foodBucket->insertTail(foodPos); // Append to food bucket
        c++;
    }
}
}

objPos Food::getFoodPos() const //getter method for obtaining a copy of the current position of the food
{
    return foodPos;
}

int Food::getX() const //getter method for obtaining a copy of the current X position of the food
{
    return foodPos.getX();
}

int Food::getY() const //getter method for obtaining a copy of the current Y position of the food
{
    return foodPos.getY();
}

char Food::getSymbol() const //getter method for obtaining a copy of the food symbol
{
    return foodPos.getSymbol();
}

void Food::getBucketPos(objPosArrayList &returnPos) const // to access food bucket
{
    returnPos = *foodBucket;
}