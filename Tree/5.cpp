#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
};

Node* newNode(int data){
    Node *node=new Node;
    node->data=data;
    node->right=node->left=NULL;
    return node;
}

void levelOrderQueue(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    Node *temp;
    while(!q.empty()){
      temp=q.front();
      cout<<temp->data<<" ";
      
      if(temp->left!=NULL){
        q.push(temp->left);
      }
      if(temp->right!=NULL){
        q.push(temp->right);
      }
      q.pop();
    }
}

int main(){
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
   
    cout<<"Level order traversal using queue \n";
    levelOrderQueue(root);

    return 0;
}