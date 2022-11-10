// Copyright 2022 Anton Minaichev <anton.minaichev@gmail.com>

#include <iostream>
#include <tasks.hpp>

// Task 5.
bool name_is_even(const std::string& name) {
    return name.length() % 2 == 0;
}

// Task 6.
bool first_is_longer(const std::string& name_one, const std::string& name_two) {
    return name_one.length() > name_two.length();
}

// Task 7.
void longest_shortest(const std::string& name_one, const std::string& name_two,
                      const std::string& name_three, std::string& the_longest,
                      std::string& the_shortest) {
  the_longest = std::max(name_one, std::max(name_two, name_three));
  the_shortest = std::min(name_one, std::min(name_two, name_three));
}


// Task 8.
std::string sub_str(const std::string& word, int m, int n) {
  std::string result;
  for (int i = m; i <= n; i++) {
    if (i < static_cast<int>(word.length())) {
      result += word[i];
    }
  }
  return std::string(result);
}


// Task 9.
void add_stars(std::string& word) {
  size_t size = word.size();
  for (size_t i = 0; i < size; i++) {
    word.insert(word.begin(), '*');
    word.push_back('*');
  }
}

// Task 10.
int percent_of_a(const std::string& word) {
  int numb_a = 0;
  int percent = 0;
  for (size_t i = 0; i < word.size(); i++) {
    if (word[i] == 'a') {
      numb_a++;
    }
  }
  percent = (numb_a * 100) / word.size();
  return percent;
}

// Task 11.
std::string replace_can(const std::string& new_word) {
    std::string str = "Can you can a can as a canner can can a can?";
    while (str.find("can") != std::string::npos) {
      str.replace(str.find("can"), 3, new_word);
    }
  return std::string(str);
}

