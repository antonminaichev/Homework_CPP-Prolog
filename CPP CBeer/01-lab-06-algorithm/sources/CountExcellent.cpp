// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

size_t CountExcellent(const std::vector<Student>& students) {
  auto good_students =
      std::count_if(students.begin(), students.end(), [](Student student) {
        return (unsigned int)std::count(student.Ratings.begin(),
                                        student.Ratings.end(),
                                        5) == student.Ratings.size();
      });
  return good_students;
}
