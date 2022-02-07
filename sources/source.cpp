// Copyright 2021 Alexey <leo678337@gmail.com>

#include <header.hpp>
#include <ctime>
#include <random>
#include <algorithm>

L_Cache::L_Cache(unsigned length)
    :size(length)
{
  init();
}

void L_Cache::init() {
  std::random_device rd;
  std::mt19937 g(rd());
  arr = new unsigned int [size];
  for (size_t i = 0; i < size; i++) {
    arr[i] = g();
  }
}

L_Cache::~L_Cache() {
  delete[] arr;
}

void L_Cache::warm_up() const {
  [[maybe_unused]] int num = 0;
  for (std::size_t i = 0; i < size; i += Step) {
    num = arr[i];
  }
}

double L_Cache::straight() {
  [[maybe_unused]] int num = 0;
  clock_t start_t = clock();

  for (std::size_t i = 0; i < Circles; i++) {
    for (std::size_t j = 0; j < size; j += Step) {
      num = arr[j];
    }
  }

  time_t end_t = clock();
  return static_cast<double>(end_t - start_t)/CLOCKS_PER_SEC;
}

double L_Cache::back() {
  [[maybe_unused]] int num = 0;
  clock_t start_t = clock();

  for (std::size_t i = 0; i < Circles; i++) {
    for (int j = size - 1; j > - 1; j -= Step) {
      num = arr[j];
    }
  }

  time_t end_t = clock();
  return static_cast<double>(end_t - start_t)/CLOCKS_PER_SEC;
}

double L_Cache::random() {
  [[maybe_unused]] int num = 0;
  std::vector<std::size_t> elements = {};
  for (std::size_t i = 0; i < size; i += Step) {
    elements.push_back(i);
  }
  std::shuffle(elements.begin(), elements.end(),
               std::mt19937(std::random_device()()));
  clock_t start_t = clock();

  for (std::size_t i = 0; i < Circles; i++) {
    for (std::size_t j = 0; j < elements.size(); j++) {
      num = arr[elements[j]];
    }
  }

  time_t end_t = clock();
  return static_cast<double>(end_t - start_t)/CLOCKS_PER_SEC;
}
