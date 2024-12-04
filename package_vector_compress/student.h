#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    if(mCap == mSize) return;
    T* mnew = new T[mSize];
    for(int i = 0 ; i < mSize; i++){
        mnew[i] = mData[i];
    }
    delete[] mData;
    mData = mnew;
    mCap = mSize;

}

#endif
