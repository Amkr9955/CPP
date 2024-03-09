// We take two explicit stacks S1 and S2.
// We insert our node to S1(if it’s not pointing to NULL).
// We will set up a while loop to run till S1 is non-empty.
// In every iteration, we pop out the top of S1 and then push this popped node to S2. Moreover we will push the left child and right child of this popped node to S1.(If they are not pointing to NULL).
// Then we start the next iteration with the next node as top of S1.
// We stop the iteration when S1 becomes empty.
// At last we start popping at the top of S2 and print the node values, we will get the postorder traversal.

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int x){
    struct node *temp=new node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
} 

void preOrder(node* root){
    if(root==NULL){
        return;
    }
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    while(!s1.empty()){
        struct node *t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left!=NULL){
            s1.push(t->left);
        }
        if(t->right!=NULL){
            s1.push(t->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
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
  
  cout << "The postOrder Traversal is : ";
  preOrder(root);

    return 0;
}
