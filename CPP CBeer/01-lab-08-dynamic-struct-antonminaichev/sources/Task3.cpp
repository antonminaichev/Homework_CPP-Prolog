// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <stack.hpp>

void Construct(Stack& stack) { stack.Top = nullptr; }

void Destruct(Stack& stack) {
  if (stack.Top == nullptr) {
    return;
  }
  while (stack.Top != nullptr) {
    Pop(stack);
  }
}

void Push(Stack& stack, int value) {
  Stack::Node* new_el = new Stack::Node;
  new_el->Data = value;
  new_el->Next = stack.Top;
  stack.Top = new_el;
}

int Pop(Stack& stack) {
  if (stack.Top == nullptr) {
    return 0;
  }
  Stack::Node* new_top = stack.Top->Next;
  int del_value = stack.Top->Data;
  delete stack.Top;
  stack.Top = new_top;
  return del_value;
}

bool Empty(const Stack& stack) {
  if (stack.Top == nullptr) {
    return true;
  }
  return false;
}
