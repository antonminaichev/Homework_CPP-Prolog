// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

std::list<int> reverseNum(std::list<int>& nums) {
  for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
    if (*iter != 0) {
      nums.insert(iter, -(*iter));
    }
  }
  return nums;
}
