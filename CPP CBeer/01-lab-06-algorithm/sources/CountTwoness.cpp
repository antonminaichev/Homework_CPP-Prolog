// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

size_t CountTwoness(const std::vector<Student>& students) {
  return std::count_if(students.begin(), students.end(), [](Student student) {
    return std::find(student.Ratings.begin(), student.Ratings.end(), 2) !=
           student.Ratings.end();
  });
}
