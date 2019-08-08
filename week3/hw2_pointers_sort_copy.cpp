/*Assignment: Implement several pointer manipulation functions : SortPointers,Swap,ReversedCopy
 * ReversedCopy may have a mutual interval between destination and source*/
#include "test_runner.h"

#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

template <typename T>
void Swap(T* first, T* second){
	T temp =  *first;
	*first = *second;
	*second = temp;

}

template <typename T>
void SortPointers(vector<T*>& pointers){
	sort(pointers.begin(),pointers.end(),[](T* a, T* b){ return *a < *b;});
}

template <typename T>
//return : half half interval : [start,begin)
pair<T*,T*> SwapInterval( T* source, size_t count,  T* destination){
	T* start = nullptr;
	T* end = nullptr;

	if (destination >= source && destination < source + count){
		start = destination;
		end = source + count;
	}else if(source >= destination && source < destination+ count){
		start = source;
		end = destination + count;
	}
	return make_pair(start,end);
}

template <typename T>
void ReversedCopy(T* source, size_t count, T* destination){
	T* src_p = source;
	T* dst_p = destination+count-1;
	pair<T*,T*> interval = SwapInterval(source,count,destination);


	while (src_p < source+count){ // passing all source mem locations in reverce
		T* middle_interval =  interval.first+ (interval.second - interval.first)/2 ;
		if (src_p>=interval.first && src_p< middle_interval){
			Swap(src_p,dst_p);
		}else if (src_p>=middle_interval && src_p< interval.second){
			// to avoid duplication
		} else{
			*dst_p = *src_p;
		}
		src_p++;
		dst_p--;
	}

}

void TestSwap() {
  int a = 1;
  int b = 2;
  Swap(&a, &b);
  ASSERT_EQUAL(a, 2);
  ASSERT_EQUAL(b, 1);

  string h = "world";
  string w = "hello";
  Swap(&h, &w);
  ASSERT_EQUAL(h, "hello");
  ASSERT_EQUAL(w, "world");
}

void TestSortPointers() {
  int one = 1;
  int two = 2;
  int three = 3;

  vector<int*> pointers;
  pointers.push_back(&two);
  pointers.push_back(&three);
  pointers.push_back(&one);

  SortPointers(pointers);

  ASSERT_EQUAL(pointers.size(), 3u);
  ASSERT_EQUAL(*pointers[0], 1);
  ASSERT_EQUAL(*pointers[1], 2);
  ASSERT_EQUAL(*pointers[2], 3);
}

void TestReverseCopy() {
  const size_t count = 7;

  int* source = new int[count];
  int* dest = new int[count];

  for (size_t i = 0; i < count; ++i) {
    source[i] = i + 1;
  }
  ReversedCopy(source, count, dest);
  const vector<int> expected1 = {7, 6, 5, 4, 3, 2, 1};
  ASSERT_EQUAL(vector<int>(dest, dest + count), expected1);
  ReversedCopy(source, count - 1, source + 1);
  const vector<int> expected2 = {1, 6, 5, 4, 3, 2, 1};
  ASSERT_EQUAL(vector<int>(source, source + count), expected2);

  delete[] dest;
  delete[] source;
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSwap);
  RUN_TEST(tr, TestSortPointers);
  RUN_TEST(tr, TestReverseCopy);
  return 0;
}
