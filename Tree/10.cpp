#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node *newNode(int x){
    struct node *temp=new node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preOrderTrav(node* root){
    if(root==NULL){
        return;
    }
  stack<node*>s;
  s.push(root);
  while(!s.empty()){
    node* t=s.top();
    s.pop();
    cout<<t->data<<" ";
    if(t->right!=NULL){
        s.push(t->right);
    }
    if(t->left!=NULL){
        s.push(t->left);
    }
    
  }
}

int main(){
  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

 

  cout << "The preOrder Traversal is : ";
  preOrderTrav(root);
  

    return 0;
}

//TC:O(N)
//SC:O(N) for auxialiary space