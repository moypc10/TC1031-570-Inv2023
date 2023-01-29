#include "Record.h"
#include <iostream>

// <-------------------> Method to save dates in timestamp <------------------->
Record::Record() {
  month = "";
  day = "";
  hour = "";
  minute = "";
  second = "";
  ip = "";
  port = "";
  failure = "";
  dateTime = 0;
}

Record::Record(std::string _month, std::string _day, std::string _hour,
               std::string _minute, std::string _second, std::string _ip,
               std::string _port, std::string _failure) {
  month = _month;
  day = _day;
  hour = _hour;
  minute = _minute;
  second = _second;
  ip = _ip;
  port = _port;
  failure = _failure;

  // Almacenar los campos en el struct tm
  dateStruct.tm_hour = std::stoi(hour);
  dateStruct.tm_min = std::stoi(minute);
  dateStruct.tm_sec = std::stoi(second);
  dateStruct.tm_mday = std::stoi(day);

  dateStruct.tm_isdst = 0;
  for (int i = 0; i < (int)months.size(); i++) {
    if (months[i] == month)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2023 - 1900;

  dateTime = mktime(&dateStruct);
}

//
// <-------------------> Method to save dates in timestamp <------------------->
std::string Record::getAll() {
  return month + " " + day + " " + hour + ":" + minute + ":" + second + " " +
         ip + ":" + port + " " + failure;
}
std::string Record::getAllD() {
  return month + " " + day + " " + hour + ":" + minute + ":" + second + " ";
}
// <----------------> Comparison of objects using timestamp <----------------->
bool Record::operator==(const Record &other) {
  return this->dateTime == other.dateTime;
}
bool Record::operator!=(const Record &other) {
  return this->dateTime != other.dateTime;
}
bool Record::operator>=(const Record &other) {
  return this->dateTime >= other.dateTime;
}
bool Record::operator<=(const Record &other) {
  return this->dateTime <= other.dateTime;
}
bool Record::operator>(const Record &other) {
  return this->dateTime > other.dateTime;
}
bool Record::operator<(const Record &other) {
  return this->dateTime < other.dateTime;
}