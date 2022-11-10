// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

std::vector<std::string> split(const std::string& str, char sep) {
  std::vector<std::string> arr;
  std::string elem;
  for (size_t i = 0; i <= str.size(); i++) {
    if (str[i] != sep && i != str.size()) {
      elem += str[i];
    } else if (!elem.empty()) {
      arr.push_back(elem);
      elem = "";
    }
  }
  return arr;
}
