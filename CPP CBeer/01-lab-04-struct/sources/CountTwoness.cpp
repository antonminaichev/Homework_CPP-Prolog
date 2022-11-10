// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

size_t CountTwoness(const std::vector<Student> &students) {
  size_t badStudents = 0;
  for (size_t i = 0; i < students.size(); i++) {
    if (std::find(students[i].Ratings.begin(), students[i].Ratings.end(), 2) !=
        students[i].Ratings.end()) {
      badStudents++;
    }
  }
  return badStudents;
}
