#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <algorithm>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  for(int i = a , j = b ; i <= (a+b)/2 ; i++,j--){
    std::swap(mData[(i+mFront)%mCap],mData[(j+mFront)%mCap]);
  }

}

#endif
