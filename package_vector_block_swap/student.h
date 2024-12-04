#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(m == 0) return false;
  if(a < this->begin() || b < this->begin() || (a + m -1) > this->end() || (b + m -1) > this->end()) return false;
  if(a == this->end() || b == this->end()) return false;
  if(!(a+m-1 < b || b+m-1 < a)) return false;
  else {
    for(int i = 0 ; i < m ; i++){
      std::swap(*(a+i),*(b+i));
    }
  }
  return true;
}

#endif
