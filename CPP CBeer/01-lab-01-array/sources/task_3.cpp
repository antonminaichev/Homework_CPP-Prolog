// Copyright 2022 Anton Minaichev <anton.minaichev@gmail.com>

#include <tasks.hpp>

// Task 3.
void swap_el(std::vector<int>& input) {
  for (int i = 0; i < 3; i++) {
    std::iter_swap(input.begin()+i, input.begin()+17+i);
  }
}
