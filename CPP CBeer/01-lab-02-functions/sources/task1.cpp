// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

// Task #1
float mean(const std::vector<float>& vec) {
  float sum = 0;
  if (!vec.empty()) {
    for (const auto& elem : vec) {
      sum += elem;
    }
    return sum / vec.size();
  }
  return 0;
}
