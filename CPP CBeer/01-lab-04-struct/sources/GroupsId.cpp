// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

std::vector<std::string> GroupsId(const std::vector<Student> &students) {
  std::vector<std::string> Ids;
  for (auto student : students) {
    if (std::find(Ids.begin(), Ids.end(), student.GroupId) == Ids.end()) {
      Ids.push_back(student.GroupId);
    }
  }
  return Ids;
}
