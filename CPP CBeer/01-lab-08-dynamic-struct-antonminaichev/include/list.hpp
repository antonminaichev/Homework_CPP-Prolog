// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <iostream>

#ifndef INCLUDE_LIST_HPP_
#define INCLUDE_LIST_HPP_

struct ForwardList {
  struct Node {
    Node* Next;
    int Data;
  };

  // Указатель на первый элемент списка.
  Node* Head;
};

void Construct(ForwardList& list);
void Destruct(ForwardList& list);

void PushFront(ForwardList& list, int value);
void PopFront(ForwardList& list);
void RemoveAfter(ForwardList::Node* node);
ForwardList::Node* InsertAfter(ForwardList::Node* node, int value);
size_t Size(const ForwardList& list);
void Reverse(ForwardList& list);

#endif  // INCLUDE_LIST_HPP_
