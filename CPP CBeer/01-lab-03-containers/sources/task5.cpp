// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

std::vector<std::string> uniqueWords(const std::string& str) {
  std::set<char> delimiters = {' ', '.', ','};
  std::vector<std::string> words;
  bool word;
  std::string substring;
  for (auto iter = str.begin(); iter < str.end(); ++iter) {
    if (delimiters.find(*iter) == delimiters.end()) {
      word = true;
      substring += (*iter);
      continue;
    } else if (!substring.empty() && word &&
               std::find(words.begin(), words.end(), substring) ==
                   words.end()) {
      word = false;
      words.push_back(substring);
      substring = "";
      continue;
    }
    substring = "";
  }
  if (!substring.empty() &&
      std::find(words.begin(), words.end(), substring) == words.end()) {
    words.push_back(substring);
  }
  return words;
}
