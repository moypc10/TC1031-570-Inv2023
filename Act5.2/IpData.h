#ifndef _IPDATA_H_
#define _IPDATA_H_

#include "Ip.h"

class IpData {
private:
  std::string ip;
  int grade;

public:
  IpData();
  IpData(Ip ip);
  std::string getIp();
  bool operator==(const IpData &) const;
  bool operator!=(const IpData &) const;
  bool operator>(const IpData &) const;
  bool operator>=(const IpData &) const;
  bool operator<(const IpData &) const;
  bool operator<=(const IpData &) const;
  friend std::ostream &operator<<(std::ostream &os, const IpData &ip);
};

inline IpData::IpData() {
  ip = " ";
  grade = 0;
}

inline IpData::IpData(Ip ip) {
  this->ip = ip.getIp();
  grade = ip.getOutDegree();
}

inline std::string IpData::getIp() { return ip; }

inline bool IpData::operator==(const IpData &other) const {
  return grade == other.grade;
}

inline bool IpData::operator!=(const IpData &other) const {
  return this->grade != other.grade;
}

inline bool IpData::operator>(const IpData &other) const {
  return this->grade > other.grade;
}

inline bool IpData::operator>=(const IpData &other) const {
  return this->grade >= other.grade;
}

inline bool IpData::operator<(const IpData &other) const {
  return this->grade < other.grade;
}

inline bool IpData::operator<=(const IpData &other) const {
  return this->grade <= other.grade;
}

inline std::ostream &operator<<(std::ostream &os, const IpData &gradeIp) {
  os << "Ip: " << gradeIp.ip << " | Grado de salida: " << gradeIp.grade;
  return os;
}

#endif //_IPDATA_H
