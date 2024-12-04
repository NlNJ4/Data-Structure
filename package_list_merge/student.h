#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  auto ls_itr = ls.begin();
  while(ls_itr!=ls.end()){
    CP::list<T> &tmp = *ls_itr;
    mHeader->prev->next = tmp.mHeader->next;
    tmp.mHeader->next->prev = mHeader->prev;
    mHeader->prev = tmp.mHeader->prev;
    tmp.mHeader->prev->next = mHeader;
    tmp.mHeader->next = tmp.mHeader;
    tmp.mHeader->prev = tmp.mHeader;
    mSize+=tmp.mSize;
    tmp.mSize=0;
    ls_itr++;
  }
}

#endif
