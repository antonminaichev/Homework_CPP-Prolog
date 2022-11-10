// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

bool is_math_exc(const Student& student) {
  for (size_t i = 0; i < student.Subjects.size(); i++) {
    if (student.Subjects[i] == "Math" && student.Ratings[i] == 5) {
      return true;
    }
  }
  return false;
}

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
  std::vector<Student> good_students = {};
  auto iter = students.begin();
  while ((iter = std::find_if(iter, students.end(), is_math_exc)) !=
         students.end()) {
    good_students.push_back(*iter);
    ++iter;
  }
  return good_students;
}
