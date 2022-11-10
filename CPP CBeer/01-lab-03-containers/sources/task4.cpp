// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

std::map<std::string, int> wordsMapCounter(const std::string& str) {
  std::set<char> delimiters = {' ', '.', ','};
  std::map<std::string, int> words;
  bool word;
  std::string substring;
  for (auto iter = str.begin(); iter < str.end(); ++iter) {
    if (delimiters.find(*iter) == delimiters.end()) {
      word = true;
      substring += (*iter);
    } else if (word) {
      word = false;
      words[substring] += 1;
      substring = "";
    }
  }
  if (!substring.empty()) {
    ++words[substring];
  }
  return words;
}
