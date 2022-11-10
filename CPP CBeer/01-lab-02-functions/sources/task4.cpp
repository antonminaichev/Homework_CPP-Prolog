// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

void sort(std::vector<float>& vec) {
  for (size_t j = 0; j < vec.size(); j++){
    for (size_t i = j; i < vec.size(); i++) {
      if (vec[i] < vec[j] && i != vec.size()) {
        std::iter_swap(vec.begin() + i, vec.begin() + j);
      }
    }
  }
}
