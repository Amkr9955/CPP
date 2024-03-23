// Problem Statement: Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.

// The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).
// Approach: 

// We perform a tree traversal and check whether the current node value is greater than the sum of node values of its children. 
// If this is the case, we simply assign its children to the same value of the current node and then recurse for the children. We do so because we are not allowed to decrement a node value. 
// So we set the children to a large value in order to increment the parent.

// It can happen in subsequent recursions that this child value is further changed, 
// therefore it is necessary that when we return to a node after returning from its children, we set it to the sum of node values of its children explicitly.

// The algorithm approach can be stated as follows:

// We perform a simple dfs traversal on the tree.
// For the base case, if the node is pointing to NULL, we simply return.
// At every node, first we find the sum of values of the children( For a NULL child, value is assumed to be 0).
// If node’s value > sum of children node value, we assign both the children’s value to their parent’s node value.
// Then we visit the children using recursion.
// After we return to the node after visiting its children, we explicitly set its value to be equal to the sum of its values of its children.
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

void changeTree(node* root){
    if(root==NULL){
        return;
    }
    int cnt=0;
    if(root->left){
        cnt+=root->left->data;
    }
    if(root->right){
        cnt+=root->right->data;
    }
    if(child>=root->data) {root->data=child;}
    else{
        if(root->left)root->left->data=root->data;
        else if(root->right) root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot=0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    if(root->left||root->right)root->data=tot;

}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  changeTree(root);

  return 0;
}