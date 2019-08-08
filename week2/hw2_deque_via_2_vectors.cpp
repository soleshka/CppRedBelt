// Example program
#include <iostream>
#include <string>
#include <vector>
//#include "test_runner.h"

using namespace std;

#define PUSH_FRONT(x) front_.push_back(x)
#define PUSH_BACK(x) back_.push_back(x)
#define FRONT() (front_.empty() ? back_.front() : front_.back())
#define BACK() (back_.empty() ? front_.front() : back_.back())

#define SIZE_RESOLVE(x) \
		if (back_.empty()) return front_[front_.size()-x-1]; \
		if (front_.empty()) return back_[x];					\
		if (x < front_.size()){								\
			return front_[front_.size()-x-1]; \
		}else  {return back_[x-front_.size()];}

#define SIZE_RESOLVE_AT(x) \
		if (back_.empty()) return front_.at(front_.size()-x-1); \
		if (front_.empty()) return back_.at(x);					\
		if (x < front_.size()){								\
			return front_.at(front_.size()-x-1); \
		}else  {return back_.at(x-front_.size());}

template <class T>
class Deque {
    private:
        vector<T> front_;
        vector<T> back_;
    public:
        Deque()  {
            front_ = {};
            back_ = {};
        }
        bool Empty() const {
            return front_.empty() && back_.empty();
        }
        size_t Size() const{
            return front_.size() + back_.size();
        }

        T& operator[](size_t index){
        	SIZE_RESOLVE(index)
        }

        const T& operator[](size_t index) const{
        	SIZE_RESOLVE(index)
        }

        T& At(size_t index){
        	SIZE_RESOLVE_AT(index)
        }

        const T& At(size_t index) const{
        	SIZE_RESOLVE_AT(index)
        }

        T& Front(){
            return FRONT() ;
        }
        const T& Front() const{
            return FRONT() ;
        }

        T& Back(){
            return BACK() ;
        }
        const T& Back() const{
            return BACK();
        }

        void PushFront(const T& elem){
            PUSH_FRONT(elem);
        }
        void PushBack(const T& elem){
            PUSH_BACK(elem);
        }
};


//void TestEmpty(){
//	Deque<int> dq;
//	ASSERT_EQUAL(dq.Empty(),true);
//
//	Deque<string> dqs;
//	ASSERT_EQUAL(dqs.Empty(),true);
//}
//void TestBack(){
//	Deque<int> dq;
//	dq.PushBack(3);
//	dq.PushBack(5);
//	ASSERT_EQUAL(dq.Back(),5);
//	ASSERT_EQUAL(dq.Front(),3);
//
//	dq.PushFront(1);
//	dq.PushFront(4);
//	ASSERT_EQUAL(dq.Back(),5);
//	ASSERT_EQUAL(dq.Front(),4);
//}
//void TestFront(){
//	Deque<int> dq;
//	dq.PushFront(1);
//	ASSERT_EQUAL(dq.Front(),1);
//	ASSERT_EQUAL(dq.Back(),1);
//	dq.PushFront(4);
//	ASSERT_EQUAL(dq.Front(),4);
//
//	dq.PushBack(3);
//	dq.PushBack(5);
//	ASSERT_EQUAL(dq.Front(),4);
//}
//void TestPushBackSize(){
//	Deque<int> dq;
//	dq.PushBack(100);
//	dq.PushBack(101);
//	dq.PushBack(102);
//	ASSERT_EQUAL(dq.Size(),3u);
//}
//void TestPushFrontSize(){
//	Deque<int> dq;
//	dq.PushFront(100);
//	dq.PushFront(101);
//	ASSERT_EQUAL(dq.Size(),2u);
//}
//void TestPushBackFrontSize(){
//	Deque<int> dq;
//	dq.PushFront(100);
//	dq.PushFront(101);
//	dq.PushBack(100);
//	dq.PushBack(101);
//	ASSERT_EQUAL(dq.Size(),4u);
//}
//void TestBackAt(){
//	Deque<int> dq;
//	dq.PushBack(17);
//	dq.PushBack(18);
//	dq.PushBack(19);
//	ASSERT_EQUAL(dq.At(0),17);
//	ASSERT_EQUAL(dq.At(1),18);
//	ASSERT_EQUAL(dq.At(2),19);
//}
//void TestFrontAt(){
//	Deque<int> dq;
//	dq.PushFront(17);
//	dq.PushFront(18);
//	dq.PushFront(19);
//	ASSERT_EQUAL(dq.At(0),19);
//	ASSERT_EQUAL(dq.At(1),18);
//	ASSERT_EQUAL(dq.At(2),17);
//}
//void TestBackFrontAt(){
//	Deque<int> dq;
//	dq.PushBack(1);
//	dq.PushBack(2);
//	dq.PushBack(3);
//	dq.PushFront(17);
//	dq.PushFront(18);
//	dq.PushFront(19);
//	ASSERT_EQUAL(dq.At(0),19);
//	ASSERT_EQUAL(dq.At(1),18);
//	ASSERT_EQUAL(dq.At(2),17);
//	ASSERT_EQUAL(dq.At(3),1);
//	ASSERT_EQUAL(dq.At(4),2);
//	ASSERT_EQUAL(dq.At(5),3);
//}
//void TestOperator(){
//	Deque<int> dq;
//	dq.PushBack(1);
//	dq.PushBack(2);
//	dq.PushBack(3);
//	dq.PushFront(17);
//	dq.PushFront(18);
//	dq.PushFront(19);
//	ASSERT_EQUAL(dq[0],19);
//	ASSERT_EQUAL(dq[1],18);
//	ASSERT_EQUAL(dq[2],17);
//	ASSERT_EQUAL(dq[3],1);
//	ASSERT_EQUAL(dq[4],2);
//	ASSERT_EQUAL(dq[5],3);
//}

int main()
{
//	TestRunner tr;
//	RUN_TEST(tr,TestEmpty);
//	RUN_TEST(tr,TestBack);
//	RUN_TEST(tr,TestFront);
//	RUN_TEST(tr,TestPushBackSize);
//	RUN_TEST(tr,TestPushFrontSize);
//	RUN_TEST(tr,TestPushBackFrontSize);
//	RUN_TEST(tr,TestBackAt);
//	RUN_TEST(tr,TestFrontAt);
//	RUN_TEST(tr,TestBackFrontAt);
//	RUN_TEST(tr,TestOperator);

}
