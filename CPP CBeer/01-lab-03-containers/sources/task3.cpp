// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

int wordsCounter(const std::string& str) {
  std::set<char> delimiters = {' ', '.', ','};
  int count = 0;
  bool word = false;
  for (auto iter = str.begin(); iter < str.end(); ++iter) {
    if (delimiters.find(*iter) != delimiters.end()) {
      word = false;
    } else if (!word) {
      word = true;
      ++count;
    }
  }
  return count;
}
