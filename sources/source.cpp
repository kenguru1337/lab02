// Copyright 2021 VladislavRz <rzhevskii_vladislav@mail.ru>

#include <header.hpp>

L_Cache::L_Cache(std::size_t length)
    :size(length)
{
  init();
}

void L_Cache::init() {
  arr = new int [size];
  for(size_t i = 0; i < size; i++) {
    arr[i] = rand();
  }
}

L_Cache::~L_Cache() {
  delete[] arr;
}

void L_Cache::warm_up() {
  [[maybe_unused]] int num = 0;
  for (std::size_t i = 0; i < size; i += 16) {
    num = arr[i];
  }
}

float L_Cache::straight() {
  [[maybe_unused]] int num = 0;
  clock_t start_t = clock();

  for(std::size_t i = 0; i < Circles; i += 16) {
    num = arr[i];
  }

  time_t end_t = clock();
  return (float)(end_t - start_t)/CLOCKS_PER_SEC;
}

float L_Cache::back() {
  [[maybe_unused]] int num = 0;
  clock_t start_t = clock();

  for(std::size_t i = Circles - 1; i > 0; i -= 16) {
    num = arr[i];
  }

  time_t end_t = clock();
  return (float)(end_t - start_t)/CLOCKS_PER_SEC;
}

float L_Cache::random() {

  return 0;
}
