// Copyright 2022 Anton Minaichev <anton.minaichev@gmail.com>

#include <tasks.hpp>

// Task 2.
int sum(const std::vector<int>& input) {
  int result = 0;
  for (size_t i = 0; i < input.size(); i++){
    result += input[i];
  }
    return result;
}

int square_sum(const std::vector<int>& input) {
  int result = 0;
  for (size_t i = 0; i < input.size(); i++){
    result += (input[i]*input[i]);
  }
    return result;
}

int sum_six(const std::vector<int>& input) {
  int result = 0;
  for (size_t i = 0; i < 6; i++){
    result += input[i];
  }
    return result;
}

int sum_k(const std::vector<int>& input, int k1, int k2) {
  int result = 0;
  for (int i = k1; i < k2+1; i++){
    result += input[i];
  }
  return result;
}

int mean(const std::vector<int>& input) {
  int result = 0, sum = 0;
  if (!input.empty()) {
    for (auto elem : input){
      sum += elem;
    }
    result = sum / input.size();
  }
    return result;
}

int mean_k(const std::vector<int>& input, int s1, int s2) {
  int result = 0, sum = 0;
  for (int i = s1; i <= s2; i++){
    sum +=input[i];
  }
  result = sum / (s2 - s1 + 1);
  return result;
}
