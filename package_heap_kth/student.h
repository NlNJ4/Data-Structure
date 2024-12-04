#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> v;
  int m = std::min(mSize,(size_t) 7);
  for(int i = 0 ; i < m ; i++) v.push_back(mData[i]);
  std::sort(v.begin(),v.end(),mLess);
  //for(int i = 0 ; i < m ; i++) printf("%d ",v[i]);
  return v[m-k];
}

#endif
