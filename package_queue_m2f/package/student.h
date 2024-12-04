#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    int position = (pos+mFront)%mCap;
    int val = mData[position];
    for(int i = mFront+pos ; i > mFront ; i--){
        mData[(i+mCap)%mCap] = mData[(i-1+mCap)%mCap];
    }
    mData[mFront] = val;
}

#endif
