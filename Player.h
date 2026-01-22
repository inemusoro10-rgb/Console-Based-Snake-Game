#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
        
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  

        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player();

        void getPlayerPos(objPosArrayList &returnPos) const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();
        void setPlayerPos(int xPos, int yPos, char sym);
        int getX() const;
        int getY() const;
        char getSymbol() const;
     
            


        // More methods to be added here

    private:
        objPosArrayList* playerPosList; // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* foodRef;
};

#endif