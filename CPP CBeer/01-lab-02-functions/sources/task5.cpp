// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

bool remove_first_negative_element(std::vector<int>& vec,
                                   int& removed_element) {
  bool remove_flag = false;
  removed_element = 0;
  for (auto iter = vec.begin(); iter < vec.end(); ++iter) {
    if (*iter < 0) {
      remove_flag = true;
      removed_element = *iter;
      vec.erase(iter);
      break;
    }
  }
  return remove_flag;
}
