// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

int main() {
  std::vector<int> v1 = {6, 8, 1, 2, 3, 4, 5};
  std::vector<int>::iterator it1 = Find(v1.begin(), v1.end(), 2);
  std::cout << "Task 1 result: " << *it1 << std::endl;
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  std::vector<int>::iterator it2 = findInSorted(v2.begin(), v2.end(), 2);
  std::cout << "Task 2 result: " << *it2 << std::endl;
  int words1 = wordsCounter("can you can");
  std::cout << "Task 3 result: " << words1 << std::endl;
  std::map<std::string, int> words2 = wordsMapCounter("can you can");
  std::cout << "Task 4 result: " << words2["can"] << ' ' << words2["you"]
            << std::endl;
  std::vector<std::string> unique = uniqueWords("Can you can");
  std::cout << "Task 5 result: " << unique.size() << std::endl;
  int words = diffWordsCounter("can you can a can");
  std::cout << "Task 6 result: " << words << std::endl;
  std::list<int> nums1 = {1, 5, 4, -3};
  reverseNum(nums1);
  std::cout << "Task 7 result: ";
  for (auto el : nums1) {
    std::cout << el << ' ';
  }
  std::cout << std::endl;
  std::vector<int> v3 = {1, 0, -8, -9, 0, 10, 23, -7};
  plusesDeleter(v3);
  std::cout << "Task 8 result: ";
  for (auto el : v3) {
    std::cout << el << ' ';
  }
  std::cout << std::endl;
  std::list<int> nums2 = {1, 5, 4, -3};
  Sort(nums2);
  std::cout << "Task 9 result: ";
  for (auto el : nums2) {
    std::cout << el << ' ';
  }
}
