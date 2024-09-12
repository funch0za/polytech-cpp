#ifndef TREE_H
#define TREE_H

#include "tree_node.hpp"

template <typename NodeType>
class Tree {
 public:
  NodeType *head;

  virtual NodeType insert(NodeType *node, int key);
  virtual void insert(int key);

  virtual NodeType remove(NodeType *node, int key);
  virtual void remove(int key);

  virtual bool find(NodeType *node, int key);
  virtual bool find(int key);

  virtual int find_min();
  virtual NodeType find_min(NodeType *node);

  virtual NodeType remove_min(NodeType *node);
};

#endif
