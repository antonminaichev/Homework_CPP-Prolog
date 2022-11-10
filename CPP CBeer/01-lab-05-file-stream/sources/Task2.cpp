// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>
#include <iostream>

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
  std::ofstream out;
  out.open(filename);
  if (out.is_open()) {
    for (auto book : data) {
      out << book.Title << std::endl
          << book.Author << std::endl
          << book.Year << std::endl;
    }
  }
  out.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
  std::ifstream in;
  std::string author;
  std::string title;
  int year;
  std::string year_str;
  outData = {};
  in.open(filename);
  if (in.is_open()) {
    if (in.peek() == std::ifstream::traits_type::eof()) {
      outData = {};
      in.close();
    }
    while (!in.eof()) {
      getline(in, title);
      getline(in, author);
      getline(in, year_str);
      year = std::stoi(year_str);
      if (title.length() != 0) {
        outData.push_back(Book{author, title, year});
      }
    }
  }
  in.close();
}
