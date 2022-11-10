// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

std::string replace(const std::string& str, const std::string& old,
                    const std::string& new_string) {
  std::string str1;
  for (size_t i = 0; i < str.length(); i++) {
    if (str.substr(i, old.length()) == old) {
      str1 += new_string;
      i += old.length() - 1;
      continue;
    }
    str1 += str[i];
  }
  return str1;
}
