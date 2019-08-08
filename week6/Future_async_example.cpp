/*
 * Assignment : Simple future/async example
 *
 * Create multithreaded Generate funtion and prove speed up in comparison to 1 thread generation
 **/

#include "profile.h"
#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using vec_type=vector<int>;
#define SIZE 100000000

int SumVector(const vec_type& vec){
	return accumulate(vec.begin(),vec.end(),0);
}
void SumTwoVectorsAsync(const vec_type& vec_a, const vec_type& vec_b){

	future<int> f = async([&vec_a]{return SumVector(vec_a);});

	auto sum = SumVector(vec_a) + f.get();

}
void SumTwoVectorsSync(const vec_type& vec_a, const vec_type& vec_b){

	auto sum = SumVector(vec_a) + SumVector(vec_b);

}

int main(){
	vec_type v1(SIZE),v2(SIZE);
	fill(v1.begin(),v1.end(),1);
	fill(v2.begin(),v2.end(),2);


	{
		LOG_DURATION("SumTwoVectorsAsync");
		SumTwoVectorsAsync(v1,v2);
	}
	{
		LOG_DURATION("SumTwoVectorsSync");
		SumTwoVectorsSync(v1,v2);
	}


	return 0;
}

