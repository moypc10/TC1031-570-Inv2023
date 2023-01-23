#ifndef _RECORD_H_
#define _RECORD_H_

#include <iostream>
#include <vector>

class Record {
private:
  std::string month, day, hour, minute, second, ip, port, failure;
  std::vector<std::string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  struct tm dateStruct;

  time_t dateTime;

public:
  Record();
  Record(std::string _month, std::string _day, std::string _hour,
         std::string _minute, std::string _second, std::string _ip,
         std::string _port, std::string _failure);
  std::string getAll();

  bool operator==(const Record &);
  bool operator!=(const Record &);
  bool operator>(const Record &);
  bool operator<(const Record &);
  bool operator>=(const Record &);
  bool operator<=(const Record &);
};

#endif /* _RECORD_H_ */