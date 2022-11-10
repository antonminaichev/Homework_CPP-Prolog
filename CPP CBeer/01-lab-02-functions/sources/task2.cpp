// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

std::pair<float, float> minMax(const std::vector<float>& vec) {
  float max_elem;
  float min_elem;
  if (!vec.empty()) {
    max_elem = vec[0];
    min_elem = vec[0];
    for (auto elem : vec) {
      if (max_elem < elem) {
        max_elem = elem;
      }
      if (min_elem > elem) {
        min_elem = elem;
      }
    }
    return std::make_pair(min_elem, max_elem);
  }
  return std::make_pair(std::numeric_limits<float>::min(),
                        std::numeric_limits<float>::max());
}
