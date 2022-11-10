// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

void SortByName(std::vector<Student>& students) {
  std::sort(students.begin(), students.end(),
            [](Student student1, Student student2) {
              return student1.Name < student2.Name;
            });
}
