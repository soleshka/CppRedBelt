/*
 * logger.h
 *
 *  Created on: 11.06.2019
 *      Author: daer
 */

#ifndef LOGGER_H_
#define LOGGER_H_


#include "test_runner.h"
#include <sstream>
#include <string>

using namespace std;

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




#endif /* LOGGER_H_ */
