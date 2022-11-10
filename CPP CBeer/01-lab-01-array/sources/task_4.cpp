// Copyright 2022 Anton Minaichev <anton.minaichev@gmail.com>

#include <iostream>
#include <tasks.hpp>

// Task 4.
void remove_negative(std::vector<int>& input) {
  for (auto iter = input.begin(); iter < input.end(); ++iter) {
    if (*iter < 0) {
      input.erase(iter);
      break;
    }
  }
}


void remove_last_even(std::vector<int>& input) {
  for (auto iter = input.end()-1; iter > input.begin(); --iter) {
    if (*iter % 2 == 0) {
      input.erase(iter);
      break;
    }
  }
}
