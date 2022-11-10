// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

std::vector<Student> VectorMathExcellent(const std::vector<Student> &students) {
  std::vector<Student> good_students = {};
  for (Student student : students) {
    for (size_t i = 0; i < student.Subjects.size(); i++) {
      if (student.Subjects[i] == "Math" && student.Ratings[i] == 5) {
        good_students.push_back(student);
      }
    }
  }
  return good_students;
}
