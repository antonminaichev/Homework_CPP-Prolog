// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>



#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

struct Stack {
  struct Node {
    Node* Next = nullptr;
    int Data = 0;
  };

  // Указатель на вверхний элемент стека.
  Node* Top = nullptr;
};

void Construct(Stack& stack);
void Destruct(Stack& stack);

void Push(Stack& stack, int value);
int Pop(Stack& stack);
bool Empty(const Stack& stack);

#endif  // INCLUDE_STACK_HPP_
