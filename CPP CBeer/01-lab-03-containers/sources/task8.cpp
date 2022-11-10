// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

std::vector<int> plusesDeleter(std::vector<int>& nums) {
  for (auto iter = nums.begin(); iter != nums.end();) {
    if (*iter > 0) {
      nums.erase(iter);
      continue;
    }
    ++iter;
  }
  return nums;
}
