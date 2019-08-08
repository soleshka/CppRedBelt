/*
 * simple_vector.h
 *
 *  Created on: 24.06.2019
 *      Author: daer
 *      Assignment: Create a simple vector implementation with basic functions ; begin , end , PushBack.
 *      Vector should follow the size and capacity of the vector.
 */

#pragma once


#include <cstdlib>

using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() =default;
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);

  T* begin();
  T* end();

  size_t Size() const;
  size_t Capacity() const;
  void PushBack(const T& value);

private:  // half interval [start,end)
  T* start_ = nullptr;
  T* end_ = nullptr;
  size_t capacity_ = 0;
  size_t size_ = 0;
  void DeleteMem();
};


template<typename T>
SimpleVector<T>::SimpleVector(size_t size){
	start_ 		= new T[size];
	capacity_	= size;
	size_		= size;
}

template<typename T>
SimpleVector<T>::~SimpleVector(){
	DeleteMem();
}

template<typename T>
T& SimpleVector<T>::operator[](size_t index){
	return start_[index];
}
template<typename T>
T* SimpleVector<T>::begin(){
	return start_;
}
template<typename T>
T* SimpleVector<T>::end(){
	return start_+size_;
}
template<typename T>
size_t SimpleVector<T>::Size() const{
	return size_;
}
template<typename T>
size_t SimpleVector<T>::Capacity() const{
	return capacity_;
}
template<typename T>
void SimpleVector<T>::PushBack(const T& value){
	if (Size()==Capacity()){

		auto new_capacity = 2*capacity_;
		if (start_==nullptr){//empty vector
			new_capacity = 1u;
		}

		T* temp = new T[new_capacity];
		size_t indx = 0;//index for original vector
		auto ptr=temp;//pointer for newly created vector
		for (;ptr != temp+capacity_;ptr++){
			*ptr = start_[indx++];
		}
		//the new element
		*ptr = value;

		//delete the previous memory
		DeleteMem();

		//assign new start_ & end_
		start_ 	= temp;
		size_++;
		capacity_=new_capacity;
	}else{
		start_[size_++]=value;
	}
}

template<typename T>
void SimpleVector<T>::DeleteMem(){
	delete[] start_;

}


