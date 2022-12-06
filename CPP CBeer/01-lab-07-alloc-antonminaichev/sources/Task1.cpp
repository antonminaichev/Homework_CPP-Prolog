// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <string.hpp>

char* CopyString(const char* str) {
  size_t size = StringLength(str);
  char* new_string = new char[size + 1]();
  memcpy(new_string, str, size);
  new_string[size] = '\0';
  return new_string;
}

char* ConcatinateStrings(const char* a, const char* b) {
  size_t size = StringLength(a) + StringLength(b);
  char* con_strings = new char[size + 1]();
  size_t size_new_str = 0;
  for (size_t i = 0; a[i] != '\0'; ++i, ++size_new_str) {
    con_strings[size_new_str] = a[i];
  }
  for (size_t i = 0; b[i] != '\0'; ++i, ++size_new_str) {
    con_strings[size_new_str] = b[i];
  }
  con_strings[size] = '\0';
  return con_strings;
}

size_t StringLength(const char* a) {
  size_t length = 0;
  for (size_t i = 0; a[i] != '\0'; ++i) {
    ++length;
  }
  return length;
}
