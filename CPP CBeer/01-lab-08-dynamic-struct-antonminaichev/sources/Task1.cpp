// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <list.hpp>

void Construct(ForwardList& list) { list.Head = nullptr; }

void Destruct(ForwardList& list) {
  if (list.Head == nullptr) {
    return;
  }
  while (list.Head->Next != nullptr) {
    RemoveAfter(list.Head);
  }
  delete list.Head;
  list.Head = nullptr;
}

void PushFront(ForwardList& list, int value) {
  ForwardList::Node* new_el = new ForwardList::Node;
  new_el->Data = value;
  new_el->Next = list.Head;
  list.Head = new_el;
}

void PopFront(ForwardList& list) {
  if (list.Head == nullptr) {
    return;
  }
  if (list.Head->Next != nullptr) {
    ForwardList::Node* new_head = list.Head->Next;
    delete list.Head;
    list.Head = new_head;
    return;
  }
    delete list.Head;
    list.Head = nullptr;
}

void RemoveAfter(ForwardList::Node* node) {
  if (node == nullptr) {
    return;
  }
  if (node->Next == nullptr) {
    return;
  }
  ForwardList::Node* next_node = node->Next->Next;
  delete node->Next;
  node->Next = next_node;
}

ForwardList::Node* InsertAfter(ForwardList::Node* node, int value) {
  if (node == nullptr) {
    return nullptr;
  }
  ForwardList::Node* el = new ForwardList::Node;
  el->Data = value;
  el->Next = node->Next;
  node->Next = el;
  return el;
}

size_t Size(const ForwardList& list) {
  if (list.Head == nullptr) {
    return 0;
  }
  size_t size = 1;
  ForwardList::Node* el = list.Head->Next;
  while (el != nullptr) {
    size++;
    el = el->Next;
  }
  return size;
}

void Reverse(ForwardList& list) {
  ForwardList::Node* current = list.Head;
  ForwardList::Node* prev = nullptr;
  ForwardList::Node* next = nullptr;
  while (current != nullptr) {
    next = current->Next;
    current->Next = prev;
    prev = current;
    current = next;
  }
  list.Head = prev;
}
