#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    int newsize = mSize+b-a;
    if (newsize+1 > mCap) expand(mCap*2);
    for(int i = 0  ; i < a ; i++) mData[mSize+b-a-i] = mData[mSize-i-1];
    for(int i = mSize +b - 2*a , j = mSize - a - 1; i >=0 && j>= mSize-b-1 ; i--,j--){
        mData[i--] = mData[j];
        mData[i] = mData[j];
    }
    mSize = mSize+b-a+1;
}

#endif