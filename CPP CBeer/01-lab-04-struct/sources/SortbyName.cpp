// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

void SortByName(std::vector<Student> &students) {
  for (size_t i = 0; i < students.size(); i++) {
    for (size_t j = i; j < students.size(); j++) {
      if (students[i].Name > students[j].Name) {
        std::iter_swap(students.begin() + i, students.begin() + j);
      }
    }
  }
}
