// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

// Structures
struct Student {
  std::string Name;
  std::string GroupId;
  std::vector<unsigned> Ratings;
  std::vector<std::string> Subjects;
};

struct Group {
  std::string Id;
  std::vector<Student> Students;
};

// Functions
void SortByName(std::vector<Student>& students);

void SortByRating(std::vector<Student>& students);

size_t CountTwoness(const std::vector<Student>& students);

size_t CountExcellent(const std::vector<Student>& students);

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students);

std::vector<std::string> GroupsId(const std::vector<Student>& students);

std::vector<Group> Groups(const std::vector<Student>& students);

#endif  // INCLUDE_HEADER_HPP_
