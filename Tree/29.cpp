// Problem Statement: Given a binary tree, Find the Lowest Common Ancestor for two given Nodes (x,y).

// Lowest Common Ancestor(LCA): The lowest common ancestor is defined between two nodes x and y as the lowest node in T that has both x and y as descendants (where we allow a node to be a descendant of itself.
// Problem Statement: Print Root to Node Path In A Binary Tree. Write a program to print path from root to a given node in a binary tree.
// We are given a binary tree T and a node V. We need to print a path from the root of the tree to the node.

// Note:

// No two nodes in the tree have the same data value.
// It is assured that the node V is present and a path always exists.

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int lowestCommonAncestor(node *root, int x, int y){
if(root==NULL){
    return -1;
}
if(root->data==x||root->data==y){
    return root->data;
}
int left=lowestCommonAncestor(root->left,x,y);
int right=lowestCommonAncestor(root->right,x,y);

if(left==-1){
return right;

}
else if(right==-1){
    return left;
}
else{
    return root->data;
}
}
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(6);
  root -> left -> right -> right = newNode(7);
  root -> right = newNode(3);

  

  int res;
  res = lowestCommonAncestor(root, 6, 7);
  cout<<res<<endl;

  return 0;
}

// TC:O(N)
// SC:O(N)