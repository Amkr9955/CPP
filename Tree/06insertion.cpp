#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

Node* newNode(int data){
    Node *temp=new Node();
    if(!temp){
        cout<<"Memory Error\n";
        return NULL;
    }
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

Node* insertRoot(Node* root,int key){
    if(root==NULL){
        root=newNode(key);
        return root;
    }
    queue<Node*>q;
    q.push(root);
    Node *t;
    while(!q.empty()){
      t=q.front();
      q.pop();
      if(t->left!=NULL){
        q.push(t->left);
      }
      else{
        t->left=newNode(key);
        return root;
      }
      if(t->right!=NULL){
        q.push(t->right);
      }
      else{
        t->right=newNode(key);
        return root;
      }

    }

}

void Inorder(Node* root){
   if(root==NULL){
    return;
   }
   Inorder(root->left);
   cout<<root->data<<" ";
   Inorder(root->right);
}


int main(){
    Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    cout<<"Inorder Traversal before insertion\n";
    Inorder(root);
    int key=12;
    root=insertRoot(root,key);
    cout<<"Inorder Trversal after insertion\n";
    Inorder(root);
    return 0;
}

//TC:O(N) N=number of nodes
//SC:auxiliary space:O(B) B=width of tree
