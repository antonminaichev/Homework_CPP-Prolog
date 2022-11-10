// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

size_t argmax(const std::vector<float>& vec) {
  size_t max_index;
  float max_elem;
  if (!vec.empty()) {
    max_index = 0;
    max_elem = vec[0];
    for (size_t i = 0; i < vec.size(); i++) {
      if (max_elem < vec[i]) {
        max_elem = vec[i];
        max_index = i;
      }
    }
    return max_index;
  }
  return -1;
}
