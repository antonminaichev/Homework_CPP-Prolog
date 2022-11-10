// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

void SortByRating(std::vector<Student> &students) {
  for (size_t i = 0; i < students.size(); i++) {
    for (size_t j = i; j < students.size(); j++) {
      float MeanRating1 = std::accumulate(students[i].Ratings.begin(),
                                          students[i].Ratings.end(), 0.0) /
                          students[i].Ratings.size();
      float MeanRating2 = std::accumulate(students[j].Ratings.begin(),
                                          students[j].Ratings.end(), 0.0) /
                          students[j].Ratings.size();
      if (MeanRating1 < MeanRating2) {
        std::iter_swap(students.begin() + i, students.begin() + j);
      }
    }
  }
}
