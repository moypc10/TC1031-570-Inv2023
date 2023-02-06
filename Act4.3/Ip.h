// Reference from Asesoria 04 de Febrero

#ifndef _IP_H_
#define _IP_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

class Ip {
private:
  std::string ip;
  int ipIndex;
  unsigned int ipValue;
  int outDegree;

public:
  Ip();
  Ip(std::string ip, int index);
  std::string getIp();
  unsigned int getIpValue();
  int getIpIndex();
  void setOutDegree(int g);
  void addToOutDegree();
  int getOutDegree();

  bool operator==(const Ip &);
  bool operator!=(const Ip &);
  bool operator>(const Ip &);
  bool operator<(const Ip &);
  bool operator>=(const Ip &);
  bool operator<=(const Ip &);
  friend std::ostream &operator<<(std::ostream &os, const Ip &ip);
};

#endif //_IP_H_