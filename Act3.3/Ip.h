// Reference from Asesoria 31 de Enero

#ifndef _IP_H_
#define _IP_H_

#include <iostream>
#include <sstream>
#include <string>

class Ip {

private:
  std::string ip;
  int n;

public:
  Ip();
  Ip(std::string ip, int n);
  bool operator==(Ip &);
  bool operator!=(Ip &);
  bool operator>(Ip &);
  bool operator<(Ip &);
  bool operator>=(Ip &);
  bool operator<=(Ip &);
  friend std::ostream &operator<<(std::ostream &os, const Ip &ip);
  int getN();
};

#endif //_IP_H_