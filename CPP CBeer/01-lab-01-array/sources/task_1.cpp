// Copyright 2022 Anton Minaichev <anton.minaichev@gmail.com>

#include <tasks.hpp>

//std::vector<int> vec = {1, 3, 5, 8, 11, 23, 102};
// Task 1.
void multi_2(std::vector<int>& input) {
  for (size_t i = 0; i < input.size(); ++i) {
    input[i] *= 2;
  }
}

void reduce_a(std::vector<int>& input, int a) {
  for (size_t i = 0; i < input.size(); ++i) {
    input[i] -= a;
  }
}

void div_on_first(std::vector<int>& input) {
  int first_elem = input[0];
  if (first_elem != 0 && !input.empty()) {
    for (size_t i = 0; i < input.size(); ++i) {
      input[i] /= first_elem;
    }
  }
}
