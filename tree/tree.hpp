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

  virtual int find_min(int key);
  virtual int find_min(NodeType *node, int key);
  
  virtual int find_max(int key);
  virtual int find_max(NodeType *node, int key);
};

#endif
