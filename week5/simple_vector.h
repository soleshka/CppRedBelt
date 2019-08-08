/*
 * simple_vector.h
 *
 *  Created on: 24.06.2019
 *      Author: Oleg Greenberg
 *      Assignment: Create a simple vector implementation with basic functions ; begin , end , PushBack.
 *      Vector should follow the size and capacity of the vector.
 *      Additional : Copy constructor and equal assignment
 */

#pragma once


#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() =default;
  explicit SimpleVector(size_t size);

  //copy ctor
  SimpleVector(SimpleVector& rhs);

  ~SimpleVector();

  T& operator[](size_t index);

  T* begin();
  T* end();

  const T* begin() const;
  const T* end() const ;
  //return size of vector
  size_t Size() const;
  //return capacity of vector
  size_t Capacity() const;

  //push_back new element.
  //increase the capasity as per requirements if it is full
  void PushBack(const T& value);

  //assignment copy constructor
  void operator=(SimpleVector& sourceVector);



private:  // half interval [start,end)
  T* start_ = nullptr;
  T* end_ = nullptr;
  size_t capacity_ = 0;
  size_t size_ = 0;
  void DeleteMem();
};



template<typename T>
SimpleVector<T>::SimpleVector(SimpleVector& rhs) :
	capacity_ (rhs.Capacity()),
	start_(new T[capacity_]),
	end_(start_+capacity_),
	size_(rhs.Size()){
	copy(rhs.begin(),rhs.end(),begin());
}

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
const T* SimpleVector<T>::begin() const{
	return start_;
}
template<typename T>
const T* SimpleVector<T>::end() const{
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

template<typename T>
void SimpleVector<T>::operator=(SimpleVector<T>& rhs){
	//delete the previous vector's memory
	DeleteMem();

	SimpleVector<T> Temp(rhs);
	swap(Temp.start_,start_);
	swap(Temp.end_,end_);
	swap(Temp.size_,size_);
	swap(Temp.capacity_,capacity_);


}
