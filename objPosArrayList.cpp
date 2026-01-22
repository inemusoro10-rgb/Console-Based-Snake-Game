#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeArray = 200; 
    sizeList = 0;

    aList = new objPos[sizeArray]; // new array on the heap
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; // Deallocate the array
    aList = nullptr; // Prevent any extra issues

}

int objPosArrayList::getSize() const
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Only works if the size of the list is less than max size
    if(sizeList < sizeArray){ 
    
    for(int i = sizeList ; i > 0 ; i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    sizeList++;
  
}
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // Only works if the size of the list is less than max size
        if(sizeList < sizeArray){
        aList[sizeList] = thisPos;
        sizeList++;
        }
}

void objPosArrayList::removeHead()
{
    // Only works if the size of the list is NOT zero (Or less than zero)
    if(sizeList>0){
    for(int i = 0; i< sizeList-1; i++){
        aList[i] = aList[i+1];
    }
    sizeList--; // Decrease list size after each removal 
}

}

void objPosArrayList::removeTail()
{
    // Only works if the list size is NOT 0 (or less than zero)
    if(sizeList>0){
    sizeList--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    // If list size is greater than zero function will return the first element 
    if(sizeList > 0){
        return aList[0];
    }

}

objPos objPosArrayList::getTailElement() const
{
    if(sizeList > 0 ){
        return aList[sizeList-1];  // Returns the tail element (last index)
}
}

objPos objPosArrayList::getElement(int index) const
{

    if(index< sizeArray && index >=0){ // If index is within list size range function will return the index value
        return aList[index];
    }

}

//copy constructor
objPosArrayList::objPosArrayList(const objPosArrayList &o)
{
    sizeArray = o.sizeArray;
    sizeList = o.sizeList;

    aList = new objPos[sizeArray];
    for(int i = 0; i < sizeList; i++)
        aList[i] = o.aList[i];
}

//copy assignment operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList &o)
{
    if(this != &o)
    {
        delete[] aList;

        sizeArray = o.sizeArray;
        sizeList = o.sizeList;

        aList = new objPos[sizeArray];
        for(int i = 0; i < sizeList; i++)
            aList[i] = o.aList[i];
    }
    return *this;
}
