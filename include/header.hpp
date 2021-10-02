// Copyright 2021 VladislavRz <rzhevskii_vladislav@mail.ru>

#include <iostream>
#include <ctime>
#include <cstdlib>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#define Circles 16385

class L_Cache {

 public:
  L_Cache(std::size_t length);
  ~L_Cache();
  void warm_up();
  float straight();
  float back();
  float random();

 private:
  void init();

 private:
  std::size_t size;
  int* arr;

};

#endif // INCLUDE_HEADER_HPP_
