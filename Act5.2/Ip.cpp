// Reference from Asesoria 04 de Febrero

#include "Ip.h"

Ip::Ip() {
  ip = "0.0.0.0";
  ipIndex = 0;
  ipValue = 0;
  outDegree = 0;
}

Ip::Ip(std::string _ip, int _index) {
  ip = _ip;
  ipIndex = _index;
  outDegree = 0;
  // Convertir IP a formato decimal
  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  std::vector<std::string> results;
  while (posFound >= 0) {
    posFound = ip.find(".", posInit);
    splitted = ip.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }
  ipValue = std::stoi(results[0]) * (pow(256, 3)) +
            std::stoi(results[1]) * (pow(256, 2)) +
            std::stoi(results[2]) * 256 + std::stoi(results[3]);
}

std::string Ip::getIp() { return ip; }

unsigned int Ip::getIpValue() { return ipValue; }

int Ip::getIpIndex() { return ipIndex; }

void Ip::setOutDegree(int g) { outDegree = g; }

void Ip::addToOutDegree() { outDegree++; }

int Ip::getOutDegree() { return outDegree; }

bool Ip::operator==(const Ip &other) { return this->ip == other.ip; }

bool Ip::operator!=(const Ip &other) { return this->ip != other.ip; }

bool Ip::operator>=(const Ip &other) { return this->ip >= other.ip; }

bool Ip::operator<=(const Ip &other) { return this->ip <= other.ip; }

bool Ip::operator>(const Ip &other) { return this->ip > other.ip; }

bool Ip::operator<(const Ip &other) { return this->ip < other.ip; }

std::ostream &operator<<(std::ostream &os, const Ip &ip) {
  os << "Ip: " << ip.ip << " - Ocurrencias: " << ip.ip;
  return os;
}
