#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector"

template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  std::vector<int> temp;
  for(int i = 0 ; i < pos ; i++){
    temp.push_back(top());
    pop();
  }
  temp.push_back(value);
  for(int i = temp.size()-1 ; i>=0 ; i--){
    push(temp[i]);
  }
}

#endif
