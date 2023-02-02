// Reference from Asesoria 31 de Enero

#include "Ip.h"

Ip::Ip() {
  this->ip = "";
  this->n = 0;
}

Ip::Ip(std::string ip, int n) {
  this->ip = ip;
  this->n = n;
}

bool Ip::operator==(Ip &other) { return this->n == other.n; }

bool Ip::operator!=(Ip &other) { return this->n != other.n; }

bool Ip::operator>=(Ip &other) { return this->n >= other.n; }

bool Ip::operator<=(Ip &other) { return this->n <= other.n; }

bool Ip::operator>(Ip &other) { return this->n > other.n; }

bool Ip::operator<(Ip &other) { return this->n < other.n; }

std::ostream &operator<<(std::ostream &os, const Ip &ip) {
  os << "Ip: " << ip.ip << " - Ocurrencias: " << ip.n;
  return os;
}

int Ip::getN() { return n; }