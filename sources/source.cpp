// Copyright 2021 VladislavRz <rzhevskii_vladislav@mail.ru>

#include <header.hpp>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>

L_Cache::L_Cache(unsigned length)
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

void L_Cache::warm_up() const {
  [[maybe_unused]] int num = 0;
  for (std::size_t i = 0; i < size; i += 16) {
    num = arr[i];
  }
}

double L_Cache::straight() {
  [[maybe_unused]] int num = 0;
  warm_up();
  clock_t start_t = clock();

  for(std::size_t i = 0; i < Circles; i += 16) {
    num = arr[i];
  }

  time_t end_t = clock();
  return static_cast<double>(end_t - start_t)*1000000/CLOCKS_PER_SEC;
}

double L_Cache::back() {
  [[maybe_unused]] int num = 0;
  warm_up();
  clock_t start_t = clock();

  for(std::size_t i = Circles - 1; i > 0; i -= 16) {
    num = arr[i];
  }

  time_t end_t = clock();
  return static_cast<double>(end_t - start_t)*1000000/CLOCKS_PER_SEC;
}

double L_Cache::random() {
  [[maybe_unused]] int num = 0;
  std::vector<std::size_t> elements = {};
  for(std::size_t i = 0; i < Circles; i += 16) {
    elements.push_back(i);
  }
  std::shuffle(elements.begin(), elements.end(),
               std::mt19937(std::random_device()()));
  warm_up();
  clock_t start_t = clock();

  for(std::size_t i = 0; i < elements.size(); i++) {
    num = arr[elements[i]];
  }

  time_t end_t = clock();
  return static_cast<double>(end_t - start_t)*1000000/CLOCKS_PER_SEC;
}
