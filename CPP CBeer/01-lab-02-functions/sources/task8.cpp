// Copyright 2022 AntonMinaichev <anton.minaichev@gmail.com>

#include <lab05.hpp>

std::string join(const std::vector<std::string>& arr, const std::string& sep) {
  std::string result;
  for (size_t i = 0; i < arr.size(); i++) {
    if (i != arr.size() - 1) {
      result.append(arr[i] + sep);
      continue;
    }
    result.append(arr[i]);
  }
  return result;
}
