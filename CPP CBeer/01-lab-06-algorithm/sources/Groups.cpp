// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

std::vector<Group> Groups(const std::vector<Student> &students) {
  std::vector<Group> groups = {};
  if (students.empty()) {
    return groups;
  }
  for (auto student : students) {
    auto iter = std::find_if(
        groups.begin(), groups.end(),
        [student](Group group) { return student.GroupId == group.Id; });
    if (iter != groups.end()) {
      iter->Students.push_back(student);
      continue;
    }
    groups.push_back({student.GroupId, {student}});
  }
  return groups;
}
