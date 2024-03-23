//Given a binary tree find the left view of it
#include <bits/stdc++.h>
using namespace std;
 
// Structure of binary tree
struct Node {
    Node* left;
    Node* right;
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

void leftview(Node* root,int level,vector<int> &ans){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    leftview(root->left,level+1,ans);
    leftview(root->right,level+1,ans);
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
    vector<int>ans;
    leftview(root,0,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}

//TC:O(N)
//SC:O(h)