// Problem Statement: BoundaryTraversal of a binary tree. Write a program for the Anti-Clockwise Boundary traversal of a binary tree.
// TC:O(N)
// SC:O(N)

// Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

// Part 1: Left Boundary of the tree (excluding the leaf nodes).
// Part 2: All the leaf nodes travelled in the left to right direction.
// Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *newNode(int x){
    struct node *temp=new node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
    }
bool isLeaf(struct node* temp){
    if(temp->left==NULL&&temp->right==NULL)
    return true;
    return false;
}

void storeLeft(struct node* root,vector<int> &ans){
    struct node *temp=root->left;
    while(temp){
    if(!isLeaf(temp)) ans.push_back(temp->data);
    if(temp->left) temp=temp->left;
    else temp=temp->right;
    }
}
void storeRight(struct node* root,vector<int> &ans){
    vector<int >ans1;
    struct node *temp=root->right;
    while(temp){
    if(!isLeaf(temp)) ans1.push_back(temp->data);
    if(temp->right) temp=temp->right;
    else temp=temp->left;
    }
   for(int i=ans1.size()-1;i>=0;i--){
      ans.push_back(ans1[i]);
   }

}
void storeLeaf(struct node* root,vector<int> &ans){
    if(isLeaf){
        ans.push_back(root->data);
        return;
    }
    if(root->left) storeLeaf(root->left,ans);
    if(root->right) storeLeaf(root->right,ans);

}

vector<int> printBoundary(struct node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    if(!isLeaf(root)) ans.push_back(root->data);

    storeLeft(root,ans);
    storeLeaf(root,ans);
    storeRight(root,ans);

    return ans;
}    


int main(){
  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}