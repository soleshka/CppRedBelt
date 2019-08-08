/*Assignment : Create a pool Class for keeping memory objects without deleting them
 when they are not in use. Relevant for objects which take long time to create like
 Threads , TCP connectors and so*/

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "profile.h"
#include "test_runner.h"
#include <set>
using namespace std;



template <class T>
class ObjectPool {
public:
  T* Allocate(){
	  return Allocate_();
  }
  T* TryAllocate(){
	return Allocate_(true);
  }

  // DEallocate memory from used_obj pool to free_obj
  //if object does not exist throw invalid_argument
  void Deallocate(T* object){
	  auto itr = used_obj.lower_bound(object);
	  if (itr !=used_obj.end()){
		  free_obj.push(*itr);
		  used_obj.erase(itr);
	  }else{
		  throw invalid_argument("object is not in use");
	  }
  }

  //Remove all allocated memory by the process
  ~ObjectPool(){
	  for (auto& elem : used_obj){
		  auto elem1 = elem;
		  delete elem1;
	  }
	  while(!free_obj.empty()){
		  delete free_obj.front();
		  free_obj.pop();
	  }
  }

private:
  queue<T*> free_obj ;
  set<T*> used_obj ;


  // move ptr from free_obj to used
  T* MoveFromFreeToUsed(){
	  T* elem;
	  elem = free_obj.front();
	  used_obj.insert(elem);
	  free_obj.pop();
	  return elem;
  }

  //allocates one elemnt
  T* AllocateOne(){
	  T* elem;
	  elem = new T;
	  used_obj.insert(elem);
	  return elem;
  }

  //wrapp func for Allocate & TryAllocate funcs
  //TryAllocate returns nullptr if no free_obj exist
  T* Allocate_(bool null_f=false){
	  T* elem;
		  if (free_obj.empty()){// no free objects
		 		return (null_f ? nullptr : AllocateOne());
		  }else {//free object has values
			  elem = MoveFromFreeToUsed();
		  }
		  return elem;
  }
};



void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
