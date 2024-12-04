#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  int new_size = mSize - pos.size();
  T* new_data = new T[new_size];
  int pos_index = 0, new_index = 0;
  for(int i = 0 ; i < this->size() ; i++){
    if(pos_index < pos.size() && i == pos[pos_index]){
      ++pos_index;
    }
    else{
      new_data[new_index++] = mData[i];
    }
  }
  delete[] mData;
  mData = new T[new_size];
  mData = new_data;
  mSize = new_size;
  mCap = new_size;
}

#endif
