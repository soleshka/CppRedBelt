/*
 * main.cpp
 *
 *  Created on: 11.06.2019
 *      Author: Oleg Greenberg
 */


#include "airline_ticket.h"
#include "test_runner.h"
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <tuple>
using namespace std;


#define LHS_FIELD(x)  lhs.x
#define RHS_FIELD(x)  rhs.x

#define SORT_BY(field) \
	[](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
	return LHS_FIELD(field) < RHS_FIELD(field);}


bool operator<(const Time& lhs, const Time& rhs){
	return tie(lhs.hours, lhs.minutes) < tie(rhs.hours, rhs.minutes);
};

bool operator==(const Time& lhs, const Time& rhs){
	return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);
};
ostream &operator <<(ostream &ostr,const Time &t){
	ostr << setfill('0') << setw(2) << t.hours  << '-'
			 << setw(2) << t.minutes;
	return ostr;
}

bool operator<(const Date& lhs, const Date& rhs){

	return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
};

bool operator==(const Date& lhs, const Date& rhs){
	return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
};
ostream &operator <<(ostream &ostr,const Date &dt){
	ostr << setfill('0') << setw(4) << dt.year  << '-'
			 << setw(2) << dt.month << '-' << setw(2) << dt.day;
	return ostr;
}

void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

void TestDate() {
	  vector<AirlineTicket> tixs = {
	    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
	    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
	    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
	    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
	    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
	  };

	  sort(begin(tixs), end(tixs), SORT_BY(departure_date));
	  ASSERT_EQUAL(tixs.front().departure_date, (Date{2018, 2,  8}));
	  ASSERT_EQUAL(tixs.back().departure_date, (Date{2018, 3,  5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
  RUN_TEST(tr, TestDate);
}
