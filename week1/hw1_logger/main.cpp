/*
 * main.cpp
 *
 *  Created on: 11.06.2019
 *      Author: daer
 */

#include <iostream>
#include "logger.h"


class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file = value; }

  void Log(const string& message);
  void LogFile();
  void LogLine();
  void SetFile(const string& file);
  void SetLine(const int& line);

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
  string file_;
  int line_;
};
#define LOG(logger, message) 		 \
			logger.SetFile(__FILE__); \
			logger.SetLine(__LINE__); \
			logger.Log(message)

  void Logger::Log(const string& message){
	  if (log_file) LogFile();
	  if (log_line) LogLine();
	  os << message << endl;

  }
  void Logger::LogFile(){
	  os << file_ << (log_line ? "" : " ");
  }
  void Logger::LogLine(){

	  os << (log_file ? ":" : "Line ");
	  os << line_  << " ";
  }

  void Logger::SetFile(const string& file){
	  file_ = file;
  }
  void Logger::SetLine(const int& line){
	  line_ = line;
  }

  void TestLog() {
	  /*something*/
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
  }

  int main() {
    TestRunner tr;
    RUN_TEST(tr, TestLog);
  }
