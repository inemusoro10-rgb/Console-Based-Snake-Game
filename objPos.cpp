#include "objPos.h"

//i added little description for what each element function does

objPos::objPos() //default constructor
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym) //additional constructor
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule


//destructor, copy constructor, copy assignment operator 
objPos::~objPos(){
    
    delete pos;

} //default constructor 

objPos::objPos(const objPos &o){

    pos = new Pos;
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;

} //copy constructor

objPos& objPos:: operator=(const objPos &o){

    if (this == &o){          // prevent self-assignment
        return *this;
    }

    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;

    return *this;

}//copy assignment operator


void objPos::setObjPos(objPos o) //updates the current object’s position and symbol using the values from another objPos object.
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym) //updates the current object's position and symbol using the given values passed as parameters 
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const //Creates a new objPos object, copies this object's x, y, and symbol values into it, and returns that new object.
{
    objPos returnPos(pos->x, pos->y, symbol);
    return returnPos;
}

char objPos::getSymbol() const //returns current symbol
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const //Checks whether the given objPos has the same (x, y) position as the current object and returns true if they match, false otherwise.
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const //if the above function is true, return the symbol, else return 0
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

int objPos::getX() const
{
    return pos->x;
}

int objPos::getY() const
{
    return pos->y;
}
