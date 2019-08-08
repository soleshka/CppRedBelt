/*
 * main.cpp
 *
 *  Created on: 12.06.2019
 *      Author: daer
 */


#include "test_runner.h"

#include <ostream>
//#include "table.h"
#include <vector>
#include <iterator>
#include <utility>
using namespace std;

template <typename T>
class Table {
	private :
		size_t rows_;
		size_t cols_;
		vector<vector<T>> table_;
	public:

	Table(size_t rows , size_t cols)  {
			Resize(rows,cols);
	}




	void Resize(const size_t& rows , const size_t& cols){
		rows_ = rows;
		cols_ = cols;

		table_.resize(rows_);
		for (auto& col_vec : table_){
			col_vec.resize(cols_);
		}

	}

	pair<size_t, size_t> Size(){
		return {table_.size(), (table_.empty() ? 0 : table_[0].size())};
	}

	  const vector<T>& operator [] (size_t idx) const {
	    return table_[idx];
	  }

	  vector<T>& operator [] (size_t idx) {
	    return table_[idx];
	  }
};
void TestTable() {
  Table<int> t(1, 2);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 2u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
