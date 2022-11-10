// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <header.hpp>

void saveToFile(const std::string& filename, const Groups& data) {
  std::ofstream out;
  out.open(filename);
  if (out.is_open()) {
    for (auto group : data) {
      out << std::endl << group.first << std::endl;
      for (auto student : group.second) {
        out << student.Year << ' ' << student.Name << std::endl;
        for (auto mark : student.RecordBook) {
          out << mark.first << ' ' << mark.second << ' ';
        }
        out << std::endl;
      }
    }
  }
  out.close();
}

void loadFromFile(const std::string& filename, Groups& outGroups) {
  std::ifstream in;
  std::string group;
  std::string name;
  int year;
  std::string str;
  std::map<std::string, Score> recordbook;
  std::string subject;
  Score mark;
  std::vector<Student> students;
  outGroups = {};
  in.open(filename);
  if (in.is_open()) {
    while (!in.eof()) {
      getline(in, str);
      if (str.empty()) {
        if (!students.empty()) {
          outGroups.insert({group, students});
          students = {};
        }
        getline(in, str);
        if (str.empty()) {
          break;
        }
        group = str;
        getline(in, str);
      }
      year = std::stoi(str.substr(0, str.find(' ')));
      str.erase(0, str.find(' ') + 1);
      name = str.substr(0);
      getline(in, str);
      while (!str.empty()) {
        subject = str.substr(0, str.find(' '));
        str.erase(0, str.find(' ') + 1);
        mark = static_cast<Score>(std::stoi(str.substr(0, str.find(' '))));
        str.erase(0, str.find(' ') + 1);
        recordbook.insert({subject, mark});
      }
      students.push_back(Student{name, year, recordbook});
      recordbook = {};
    }
  }
  in.close();
}
