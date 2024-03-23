//Check if binary Tree is balanced Binary Tree

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node *left,*right;
};

Node* newNode(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;

}
int heightTree(Node *root){
     if(root==NULL){
      return 0;
     }
    int lh=heightTree(root->left);
    if(lh==-1){
        return -1;
    }
    int rh=heightTree(root->right);
     if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return max(lh,rh)+1;
}

bool isBalanced(Node *root){
    return heightTree(root)!=-1;
   
}




int main(){
    Node *root=newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    bool binarytree=isBalanced(root);
    if(binarytree){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}
//TC:O(N);
//SC:O(1) Extra Space + O(H) Recursion Stack space,