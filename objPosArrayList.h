#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int sizeList;
        int sizeArray;

    public:
        objPosArrayList();
        ~objPosArrayList();

        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;

        //new
        objPosArrayList(const objPosArrayList &other);
        objPosArrayList& operator=(const objPosArrayList &other);

};

#endif