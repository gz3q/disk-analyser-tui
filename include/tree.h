#ifndef TREE_H
#define TREE_H

typedef struct TreeNode TreeNode;

struct TreeNode {
  int data;
  struct TreeNode *firstChild;
  struct TreeNode *nextSibling;
};

#endif
