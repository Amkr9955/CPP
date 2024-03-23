//Maximum sun Path Binary Tree //Approach 1 worst case
//Problem Statement: Write a program to find the maximum sum path in a binary tree. A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge. 
// A node can only appear in the sequence at most once. 
// A path need not pass from the root. We need to find the path with the maximum sum in the binary tree.
// https://www.youtube.com/watch?v=Op6YFcs8R9M

#include <bits/stdc++.h>

using namespace std;

int maxSum;

struct node {
  int data;
  struct node * left, * right;
};
struct node* newNode(int data);

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int maxPathSum(struct node* root){
    if (root==NULL)
    return 0;
    int ls=maxPathSum(root->left);
    int rs=maxPathSum(root->right);

    int singlepath=max(root->data,max(ls,rs)+root->data);
    int loop_and_single_max=max(singlepath,ls+rs+root->data);
    maxSum=max(maxSum,loop_and_single_max);

    return singlepath;

}

int main() {

  struct node * root = newNode(-10);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);
  
  maxSum=INT_MIN;
  maxPathSum(root);
  cout << "The Max Path Sum for this tree is " << maxSum;

  return 0;
}
//TC:O(N)
//SC:O(N)