// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <limits>
#include <list>
#include <map>
#include <set>

#ifndef INCLUDE_LAB_HPP_
#define INCLUDE_LAB_HPP_

//Task #1
std::vector<int>::iterator Find(std::vector<int>::iterator first,
                                std::vector<int>::iterator last, int el);

//Task #2
std::vector<int>::iterator findInSorted(std::vector<int>::iterator first,
                                       std::vector<int>::iterator last,
                                       int el);

//Task #3
int wordsCounter(const std::string& str);

//Task #4
std::map<std::string, int> wordsMapCounter(const std::string& str);

//Task #5
std::vector<std::string> uniqueWords(const std::string& str);

//Task #6
int diffWordsCounter(const std::string& str);

//Task #7
std::list<int> reverseNum(std::list<int>& nums);

//Task #8
std::vector<int> plusesDeleter(std::vector<int>& nums);

//Task #9
std::list<int> Sort(std::list<int>& nums);

#endif // INCLUDE_LAB_HPP_
