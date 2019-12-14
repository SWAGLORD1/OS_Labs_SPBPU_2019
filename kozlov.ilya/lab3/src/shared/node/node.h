#ifndef NODE_H
#define NODE_H

#include <sys/types.h>
#include <pthread.h>
#include <functional>

template<typename T>
struct Node
{
  T item;
  int key;
  pthread_mutex_t mutex;
  Node *next;

  // TODO: handle error
  explicit Node(T item);
  bool operator==(const Node& other);
  int lock();
  int unlock();
  ~Node();
};

#include "node.hpp"

#endif // NODE_H