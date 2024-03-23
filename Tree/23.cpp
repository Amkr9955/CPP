// Print Nodes in Top View of Binary Tree

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

void topview(Node* root){
    queue<pair<Node*,int>>q;
    map<int,int>mpp;
    if(root==NULL){
        return;
    }
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node *temp=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()){
            mpp[line]=temp->data;
        }
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
    topview(root);
    return 0;
}

//TC:O(N)
//SC:O(N)