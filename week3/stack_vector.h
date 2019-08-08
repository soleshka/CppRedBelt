/*
 * stack_vector.h
 *
 *  Created on: 25.06.2019
 *      Author: Oleg Greenberg
 *      Assignment: Create a vector based on stack memory allocation and array container
 */

#pragma once

#include <stdexcept>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
private:
	array<T,N> db;
	size_t contained_size_;

public:
	  explicit StackVector(size_t a_size = 0) : contained_size_(a_size) {
	    if (a_size >N) {
	      throw invalid_argument("Too much");
	    }
	  }



  T& operator[](size_t index);
  const T& operator[](size_t index) const;

  typename array<T,N>::iterator begin();
  typename array<T,N>::iterator end();
  typename array<T,N>::const_iterator begin() const;
  typename array<T,N>::const_iterator end() const;

  size_t Size() const;
  size_t Capacity() const;

  void PushBack(const T& value);
  T PopBack();

};

template <typename T, size_t N>
T& StackVector<T,N>::operator[](size_t index) {
  return db[index];
}
template <typename T, size_t N>
const T& StackVector<T,N>::operator[](size_t index) const {
  return db[index];
}

template <typename T, size_t N>
size_t StackVector<T,N>::Size() const{
	return contained_size_;
}
template <typename T, size_t N>
size_t StackVector<T,N>::Capacity() const{
	return db.size();
}

template <typename T, size_t N>
void StackVector<T,N>::PushBack(const T& value){
	if (contained_size_==db.size()){
		throw overflow_error("overflow");
	}else {
		db[contained_size_++] = value;
	}
}

template <typename T, size_t N>
T StackVector<T,N>::PopBack(){
	if (contained_size_==0){
		throw underflow_error("underflow");
	}else {
		T val = db[--contained_size_];
		return val;
	}
}

template <typename T, size_t N>
typename array<T,N>::iterator StackVector<T,N>::begin(){
	return db.begin();
}

template <typename T, size_t N>
typename array<T,N>::iterator StackVector<T,N>::end(){

	return db.begin()+contained_size_;
}

template <typename T, size_t N>
  typename array<T,N>::const_iterator StackVector<T,N>::begin() const{
	return db.begin();
}

template <typename T, size_t N>
  typename array<T,N>::const_iterator StackVector<T,N>::end() const{
	return db.begin()+contained_size_;
}
