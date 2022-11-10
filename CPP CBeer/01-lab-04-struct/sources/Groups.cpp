// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

std::vector<Group> Groups(const std::vector<Student> &students) {
  std::vector<Group> groups = {};
  if (students.empty()) {
    return groups;
  }
  groups.push_back({students[0].GroupId, {}});
  for (auto student : students) {
    size_t group_indx = 0;
    for (auto &group : groups) {
      if (student.GroupId == group.Id) {
        groups[group_indx].Students.push_back(student);
        break;
      }
      group_indx++;
    }
    if (group_indx == groups.size()) {
      groups.push_back({student.GroupId, {student}});
    }
  }
  return groups;
}
