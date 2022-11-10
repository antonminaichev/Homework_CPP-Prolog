// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

int diffWordsCounter(const std::string& str) {
  std::vector<std::string> words = uniqueWords(str);
  return words.size();
}
