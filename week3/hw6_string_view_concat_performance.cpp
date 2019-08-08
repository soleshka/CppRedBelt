//Assignment : Check the better performance for string_view concutenation
#include "profile.h"
#include <random>
#include <stdexcept>
#include <string_view>
#include <array>
#include <iostream>
#include <sstream>

using namespace std;


//string ConcatenateStringViews(
//    string_view lhs, string_view rhs) {
//  return lhs + rhs;
//}

std::string ConcatenateStringViews1(
    std::string_view lhs, std::string_view rhs) {
  std::string s;
  s.reserve(lhs.size() + rhs.size());
  return (s += lhs) += rhs;
}

//std::string ConcatenateStringViews2(
//    std::string_view lhs, std::string_view rhs) {
//  std::string s;
//  s.reserve(lhs.size() + rhs.size());
//  return s += lhs += rhs;
//}

std::string ConcatenateStringViews3(
		std::string_view lhs, std::string_view rhs) {
  return std::string(lhs) + std::string(rhs);
}

string ConcatenateStringViews4(
    string_view lhs, string_view rhs) {
  string s(lhs);
  s.reserve(s.size() + rhs.size());
  s += rhs;
  return s;
}


string ConcatenateStringViews5(
    string_view lhs, string_view rhs) {
  ostringstream s;
  s << lhs << rhs;
  return s.str();
}

string ConcatenateStringViews6(
    string_view lhs, string_view rhs) {
  string s(lhs);
  s += rhs;
  return s;
}

string ConcatenateStringViews7(
    string_view lhs, string_view rhs) {
  return string(lhs) += rhs;
}



const int SIZE = 10000000;

string CreateString(string k){
	string s="";
	for(int i=0;i<SIZE;i++){
		s += k;
	}
	return s;
}

void TestStringViewDuration(){
	const string s= CreateString("a");
		const string ss= CreateString("b");
		string_view s1 = s;
		string_view s2 =ss;


		//std::cout << ConcatenateStringViews(s1,s2);
		//std::cout << ConcatenateStringViews2(s1,s2);

		{
			LOG_DURATION("2nd");
			auto ssss = ConcatenateStringViews1(s1,s2) ;
		}
		{
			LOG_DURATION("3rd");
			auto ssss =ConcatenateStringViews3(s1,s2) ;
		}
		{
			LOG_DURATION("4th");
			auto ssss =ConcatenateStringViews4(s1,s2) ;
		}
		{
			LOG_DURATION("5th");
			auto ssss =ConcatenateStringViews5(s1,s2) ;
		}
		{
			LOG_DURATION("6th");
			auto ssss = ConcatenateStringViews6(s1,s2) ;
		}
		{
			LOG_DURATION("7th");
			auto ssss = ConcatenateStringViews7(s1,s2) ;
		}
}

int main() {

	TestStringViewDuration();




	return 0;
}
