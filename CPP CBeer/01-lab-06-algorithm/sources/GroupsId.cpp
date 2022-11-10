// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

std::vector<std::string> GroupsId(const std::vector<Student>& students) {
  std::vector<std::string> groups;
  for (auto student : students) {
    if (std::find(groups.begin(), groups.end(), student.GroupId) ==
        groups.end()) {
      groups.push_back(student.GroupId);
    }
  }
  return groups;
}
