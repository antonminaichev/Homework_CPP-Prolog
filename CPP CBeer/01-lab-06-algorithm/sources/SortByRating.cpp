// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

bool sort_rating(Student student1, Student student2) {
  float a_rating =
      std::accumulate(student1.Ratings.begin(), student1.Ratings.end(), 0.0) /
      student1.Ratings.size();
  float b_rating =
      std::accumulate(student2.Ratings.begin(), student2.Ratings.end(), 0.0) /
      student2.Ratings.size();
  return a_rating > b_rating;
}

void SortByRating(std::vector<Student>& students) {
  std::sort(students.begin(), students.end(), sort_rating);
}
