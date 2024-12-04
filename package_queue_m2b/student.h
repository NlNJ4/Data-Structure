#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  int position = (pos+mFront)%mCap;
  int val = mData[position];
  //printf("%d",val);
  for(int i = mFront+pos ; i < mFront+mSize-1 ; i++){
      mData[(i+mCap)%mCap] = mData[(i+mCap+1)%mCap];
  }
  mData[(mFront+mSize-1)%mCap] = val;
}

#endif
