/*
 * Assignment : Family account class. Should control the balance of several family members .
 * #mutex, #async , #lock_guard
 **/

#include "profile.h"
#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <mutex>
#include <future>

using namespace std;

#define BALANCE 100000

template<typename T>
class Account{
private:
	T balance_;
	mutex m;
public:
	Account(T balance): balance_(balance){}
	bool Spend(T value){
		lock_guard<mutex> lock(m);
		if(value <= balance_){
			balance_ -= value;
			return true;
		}
		return false;
	}

	T Balance(){
		return balance_;
	}

	void PrintBalance(){
		cout << "Family balance: "<<Balance() << endl;
	}
};


//host to spend mopney from a given account

template<typename T>
T SpendMoney(Account<T>& account){
	auto spent = 0;
	for (auto i=0; i<BALANCE; i++){
		if (account.Spend(1)){
			spent+=1;
		}
	}
	return spent;
}

int main(){
	Account<int> family_account(BALANCE);

	//use SpendMoney<int>  as this is a function template
	auto user1 = async(SpendMoney<int>,ref(family_account));
	auto user2 = async(SpendMoney<int>,ref(family_account));
	auto user3 = async(SpendMoney<int>,ref(family_account));
	auto user4 = async(SpendMoney<int>,ref(family_account));

	int total_spent = user1.get() + user2.get() + user3.get() + user4.get();
	cout << "Spent : " << total_spent  << endl;
	family_account.PrintBalance();
	return 0;
}

