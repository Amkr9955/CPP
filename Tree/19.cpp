//Problem Statement: Given the root of a binary tree, return the zigzag level order traversal of Binary Tree. (i.e., from left to right, then right to left for the next level and alternate between).
#include <iostream>
#include <stack>
using namespace std;
 
// Binary Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

void zigzagtraversal(struct Node* root){
    if(root==NULL)
    return;
    stack<struct Node*>currlvl;
    stack<struct Node*>nextlvl;
    currlvl.push(root);
    bool lefttoright=true;
    while(!currlvl.empty()){
        struct Node *temp=currlvl.top();
        currlvl.pop();
        if(temp){
            cout<<temp->data<<" ";

            if(lefttoright){
                if(temp->left)
                nextlvl.push(temp->left);
                if(temp->right)
                nextlvl.push(temp->right);
            }
            else{
                if(temp->right)
                nextlvl.push(temp->right);
                if(temp->right)
                nextlvl.push(temp->left);
            }
        }
        if(currlvl.empty()){
          lefttoright=!lefttoright;
          swap(currlvl,nextlvl);
        }

    }

}

// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// driver program to test the above function
int main()
{
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
 
    zigzagtraversal(root);
 
    return 0;
}

// Time Complexity: O(n) 
// Space Complexity: O(n)+(n)=O(n)