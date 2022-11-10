// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <fstream>
#include <map>
#include <string>
#include <vector>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

// Structures
enum Score { Unsatisfactorily = 2, Satisfactorily, Good, Excellent };

struct Student {
  std::string Name;
  int Year;
  std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;

struct Book {
  std::string Author;
  std::string Title;
  int Year;
};

// Functions
void saveToFile(const std::string& filename,
                const std::vector<std::string>& data);

void loadFromFile(const std::string& filename,
                  std::vector<std::string>& outData);

void saveToFile(const std::string& filename, const std::vector<Book>& data);

void loadFromFile(const std::string& filename, std::vector<Book>& outData);

void saveToFile(const std::string& filename, const Groups& data);

void loadFromFile(const std::string& filename, Groups& outGroups);

#endif  // INCLUDE_HEADER_HPP_
