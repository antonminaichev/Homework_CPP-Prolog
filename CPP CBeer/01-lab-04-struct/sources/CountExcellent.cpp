// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

size_t CountExcellent(const std::vector<Student> &students) {
  size_t goodStudents = students.size();
  for (size_t i = 0; i < students.size(); i++) {
    for (size_t j = 0; j < students[i].Ratings.size(); j++) {
      if (students[i].Ratings[j] != 5) {
        goodStudents--;
        break;
      }
    }
  }
  return goodStudents;
}
