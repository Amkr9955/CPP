//maximaum deapth of a binary tree

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

int binaryHeight(Node *root){
    if(root==NULL){
      return 0;
    }
    int lh=binaryHeight(root->left);
    int rh=binaryHeight(root->right);
    return lh>=rh?lh+1:rh+1;
}


int main(){
    Node *root=newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int height=binaryHeight(root);
    cout<<height<<endl;
    return 0;
}
//TC:O(N);
//SC:O(1) Extra Space + O(H) Recursion Stack space,