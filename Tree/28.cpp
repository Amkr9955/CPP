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

bool getPath(node* root,vector<int> &arr,int key){
    if(root==NULL){
        return false;
    }
    arr.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPath(root->left,arr,key)||getPath(root->right,arr,key))
    return true;

    arr.pop_back();
    return false;
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(6);
  root -> left -> right -> right = newNode(7);
  root -> right = newNode(3);

  vector < int > arr;

  bool res;
  res = getPath(root, arr, 7);

  cout << "The path is ";
  for (auto it: arr) {
    cout << it << " ";
  }

  return 0;
}

// TC:O(N)
// SC:O(N)