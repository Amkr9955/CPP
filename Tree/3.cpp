// https://www.youtube.com/watch?v=wGXB9OWhPTg

// Step 1: Initialize the current node as the root.

// Step 2: While the current is not NULL, 

// If the current node does not have a left child, print the current node’s value and update it to point to the right, i.e. current = current->right.
// If the current node has a left child, then first connect the rightmost node of the left subtree to the root and then update the current node to point to the left, i.e. current = current-> left.
 

// Update the right child as NULL of the node whose right child is node current and print the current’s value. Then move to right i.e., current = current->right.
// OR

// Make current as of the right child of that rightmost node we found and then go to this left child, i.e., current = current->left.
// Step 3: Then, after printing the current node and traversing through it, we remove the threaded link, and the current node is updated to point to the right.

 

// Step 4: After traversing all the nodes of the left subtree and printing the root node, we move to the right subtree by pointing the current node to the right.

 

// Hence, After traversing through the whole binary tree, we have achieved our output. 

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};



struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
 void inOrder(struct Node* root){

     struct Node *curr,*pre;

     if(root==NULL){
        return;
     }

     curr=root;

     while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }

        }
     }

 }

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    inOrder(root);
 
    return 0;
}