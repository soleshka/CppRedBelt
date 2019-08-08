/*
 * Assignment: Create a Translator class to translate from one language to another.
 * Requirement : each world should not occupy more then 1 memory location (string_view implementaiton)
 * */
#include "profile.h"
#include "test_runner.h"
#include <deque>
#include <iostream>
#include <map>
#include <string_view>
#include <vector>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target);
  string_view TranslateForward(string_view source) const;
  string_view TranslateBackward(string_view target) const;

private:
  map<string_view,string_view> s2t;
  map<string_view,string_view> t2s;
  deque<string> db;

  string_view ResolveTranslation(const map<string_view,string_view>& mp, const string_view& what) const;
  string_view ResolveAddition(string_view s);
};


string_view Translator::ResolveAddition(string_view s) {
    for (const auto* map_ptr : {&s2t, &t2s}) {
      const auto it = map_ptr->find(s);
      if (it != map_ptr->end()) {
        return it->first;
      }
    }
    return db.emplace_back(s);
  }


void Translator::Add(string_view source, string_view target){
	 const string_view source_view = ResolveAddition(source);
	 const string_view target_view = ResolveAddition(target);
	 s2t[source_view] = target_view;
	 t2s[target_view] = source_view;
}

string_view Translator::TranslateForward(string_view source) const{
	return ResolveTranslation(s2t,source);
}
string_view Translator::TranslateBackward(string_view target) const{
	return ResolveTranslation(t2s,target);
}

string_view Translator::ResolveTranslation(const map<string_view,string_view>& mp, const string_view& what) const{
	if (const auto& it = mp.find(what); it != mp.end()){
		return it->second;
	}else{
		return {};
	}
}

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
