// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <lab.hpp>

std::vector<int>::iterator Find(std::vector<int>::iterator first,
                                std::vector<int>::iterator last, int el) {
  for (auto iter = first; iter < last; ++iter) {
    if (*iter == el) {
      return iter;
    }
  }
  return last;
}
