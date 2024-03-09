//recursive traversal tree

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left,*right;
};

//to create new tree node
Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;

}

void printInorder(struct Node* &root){
     if(root){
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
     }
}

void printPreorder(struct Node* &root){
     if(root){
        cout<<root->data<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
     }
}

void printPostorder(struct Node* &root){
     if(root){
        printPostorder(root->left);
        printPostorder(root->right);
        cout<<root->data<<" ";
     }
}

int main(){
    struct Node* root=newNode(1);   //root pointer
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    cout<<"The inorder travesal of binary tree is \n";
    printInorder(root);
    cout<<'\n';
    
    cout<<"The preorder travesal of binary tree is \n";
    printPreorder(root);
    cout<<'\n';

    cout<<"The postorder travesal of binary tree is \n";
    printPostorder(root);
    cout<<'\n';

    return 0;
}

// Time Complexity:O(N)