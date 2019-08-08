#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "profile.h"
#include <set>
using namespace std;



class Learner {
 private:
  vector<string> dict;

 public:
  int Learn(const vector<string>& words) {
    set<string> s_temp ;
    int orig_size = dict.size();
    {
    	LOG_DURATION("Dict to Set");
    	copy(dict.begin(),dict.end(),inserter(s_temp,s_temp.end()));
    }
    {
    	LOG_DURATION("Words to Set");
    	copy(words.begin(),words.end(),inserter(s_temp,s_temp.end()));
    }
    {
    	LOG_DURATION("Dict clear");
    	dict.clear();
    }
    {
    	LOG_DURATION("Set to Dict");
    	copy(s_temp.begin(),s_temp.end(),back_inserter(dict));
    }
    return dict.size()-orig_size;
  }

  vector<string> KnownWords() {
    //sort(dict.begin(), dict.end());
    //dict.erase(unique(dict.begin(), dict.end()), dict.end());
    return dict;
  }
};


//class Learner {
// private:
//  vector<string> dict;
//
// public:
//  int Learn(const vector<string>& words) {
//    int newWords = 0;
//    for (const auto& word : words) {
//      if (find(dict.begin(), dict.end(), word) == dict.end()) {
//        ++newWords;
//        dict.push_back(word);
//      }
//    }
//    return newWords;
//  }
//
//  vector<string> KnownWords() {
//    sort(dict.begin(), dict.end());
//    dict.erase(unique(dict.begin(), dict.end()), dict.end());
//    return dict;
//  }
//};

void MakeVector(vector<string>& v1, int n){
	for (int x = 0; x <n; x++){
		v1.push_back("a"+to_string(x));
	}
}

void TestLerner(){
	Learner lr;

	vector<string> v1;
	MakeVector(v1,10000);

	{
		LOG_DURATION("Learn");
		lr.Learn(v1);
	}
	{
		LOG_DURATION("KnownWords");
		auto vec = lr.KnownWords();
	}
}
int main() {

 TestLerner();
//  Learner learner;
//  string line;
//  while (getline(cin, line)) {
//    vector<string> words;
//    stringstream ss(line);
//    string word;
//    while (ss >> word) {
//      words.push_back(word);
//    }
//    cout << learner.Learn(words) << "\n";
//  }
//  cout << "=== known words ===\n";
//  auto vec = learner.KnownWords();
//  for (const auto& word : vec) {
//    cout << word << "\n";
//  }
}
