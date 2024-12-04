#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(),data.end());
  int total_insertions = data.size();
  int new_size = mSize + total_insertions;
  T* new_data = new T[new_size];

  int data_index = 0; 
  int offset = 0;   

  for (int i = 0; i < mSize + total_insertions; ++i) {
    if (data_index < total_insertions && i == data[data_index].first + offset) {
      new_data[i] = data[data_index].second;
      ++data_index;
      ++offset;
    } else {
      new_data[i] = mData[i - offset];
    }
  }

  delete[] mData;
  mData = new_data;
  mSize = new_size;
  mCap = new_size;
}

#endif
