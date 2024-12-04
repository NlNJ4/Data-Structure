#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

bool reverses = 0;

template <typename T>
void CP::queue<T>::reverse() {
  reverses = ! reverses;
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  if(!reverses) return mData[mFront];
  else return mData[(mFront + mSize - 1)%mCap];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  if(!reverses) return mData[(mFront + mSize - 1) % mCap];
  else return mData[mFront];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if(!reverses) mData[(mFront + mSize) % mCap] = element;
  else{
    mFront = (mFront-1+mCap) % mCap;
    mData[mFront] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(!reverses) mFront = (mFront + 1) % mCap;
  mSize--;
}

#endif