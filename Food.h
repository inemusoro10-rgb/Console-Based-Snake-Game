#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"


class Food{
private:
    objPos foodPos;
    GameMechs* mainGameMechsRef;
    objPosArrayList* foodBucket;
   

public:
    Food(GameMechs* thisGMRef);    
    ~Food();

    void generateFood(const objPosArrayList &blockOffList);
    objPos getFoodPos() const;
    int getX() const;
    int getY() const;
    char getSymbol() const;

    // new 
    void getBucketPos(objPosArrayList &returnPos) const;

};

#endif
