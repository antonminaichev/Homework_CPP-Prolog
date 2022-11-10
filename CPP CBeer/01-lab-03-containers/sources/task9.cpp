// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

std::list<int> Sort(std::list<int> &nums) {
  for (auto iter1 = nums.begin(); iter1 != nums.end(); ++iter1) {
    for (auto iter2 = iter1; iter2 != nums.end(); ++iter2) {
      if (*iter2 > *iter1) {
        std::swap(*iter1, *iter2);
      }
    }
  }
  return nums;
}
