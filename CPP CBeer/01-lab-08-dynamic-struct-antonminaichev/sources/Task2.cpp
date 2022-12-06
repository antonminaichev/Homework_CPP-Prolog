// Copyright 2022 antonminaichev <anton.minaichev@gmail.com>

#include <queue.hpp>

void Construct(Queue& queue) {
  queue.Head = nullptr;
  queue.Tail = queue.Head;
}

void Destruct(Queue& queue) {
  if (queue.Head == nullptr) {
    return;
  }
  while (queue.Head != nullptr) {
    Pop(queue);
  }
}

void Push(Queue& queue, int value) {
  Queue::Node* new_el = new Queue::Node;
  new_el->Data = value;
  new_el->Next = nullptr;
  if (queue.Head == nullptr) {
    queue.Head = new_el;
    queue.Tail = new_el;
  } else if (queue.Head == queue.Tail) {
    queue.Tail = new_el;
    queue.Head->Next = new_el;
  } else {
    queue.Tail->Next = new_el;
    queue.Tail = new_el;
  }
}

int Pop(Queue& queue) {
  if (queue.Head == nullptr) {
    return 0;
  }
  int del_value = queue.Head->Data;
  Queue::Node* new_head = queue.Head->Next;
  delete queue.Head;
  if (queue.Tail == queue.Head) {
    queue.Tail = new_head;
  }
  queue.Head = new_head;
  return del_value;
}

bool Empty(const Queue& queue) {
  if (queue.Head == nullptr) {
    return true;
  }
  return false;
}
