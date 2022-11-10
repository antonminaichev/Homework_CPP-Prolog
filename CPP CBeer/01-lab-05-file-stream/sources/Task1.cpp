// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

void saveToFile(const std::string& filename,
                const std::vector<std::string>& data) {
  std::ofstream out;
  out.open(filename);
  if (out.is_open()) {
    for (auto iter = data.begin(); iter != data.end(); ++iter) {
      if (iter != data.end() - 1) {
        out << *iter << std::endl;
        continue;
      }
      out << *iter;
    }
  }
  out.close();
}

void loadFromFile(const std::string& filename,
                  std::vector<std::string>& outData) {
  std::ifstream in;
  std::string word;
  outData = {};
  in.open(filename);
  if (in.is_open()) {
    if (in.peek() == std::ifstream::traits_type::eof()) {
      outData = {};
      in.close();
    }
    while (getline(in, word, '\n')) {
      outData.push_back(word);
    }
  }
  in.close();
}
