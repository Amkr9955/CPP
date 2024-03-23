// Problem Statement: Given a binary tree, print the bottom view from left to right. A node is included in the bottom view if it can be seen when we look at the tree from the bottom.

#include <bits/stdc++.h>
using namespace std;
 
// Structure of binary tree
struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};
 
// function to create a new node
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

void bottomview(Node* root){
    if(root==NULL){
        return;
    }
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node *temp=it.first;
        int line=it.second;
        mpp[line]=temp->data;
        if(temp->left!=NULL){
            q.push({temp->left,line-1});
        }
        if(temp->right!=NULL){
            q.push({temp->right,line+1});
        }
    }
    for(auto i:mpp){
        cout<<i.second<<" ";
    }
}

int main()
{
    /* Create following Binary Tree
         1
        / \
       2   3
        \
          4
           \
            5
              \
               6
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    bottomview(root);
    return 0;
}

//TC:O(N)
//SC:O(N)