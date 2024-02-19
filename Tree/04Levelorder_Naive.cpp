// https://youtu.be/ICpp88mcB-k?si=FKb82zkK6cGoU_rg


#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
};
void printCurrentLevel(node* root,int lvl){
    if(root==NULL){
        return;
    }
    if(lvl==1){
        cout<<root->data<<" ";
    }
    if(lvl>1){
        printCurrentLevel(root->left,lvl-1);
        printCurrentLevel(root->right,lvl-1);

    }
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);

    if(lh>rh){
        return lh+1;
    }
    else{
        return rh+1;
    }
}

void printLevelOrder(node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printCurrentLevel(root,i);
    }
}

node *newNode(int data){
    node *Node=new node;
    Node->data=data;
    Node->left=Node->right=NULL;
    return Node;

}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}

// TC:O(n^2)
// SC:O(1) auxiliary O(n) for recursion stack