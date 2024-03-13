//preorder using 1 stack
#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

vector < int > postOrderTrav(node * curr){
    vector<int>ans;
    if(curr==NULL){
        return ans;
    }
     stack<node*>s;
   
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            node *temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty()&&temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;
}

int main() {

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

  vector < int > postOrder;
  postOrder = postOrderTrav(root);

  cout << "The postOrder Traversal is : ";
  for (int i = 0; i < postOrder.size(); i++) {
    cout << postOrder[i] << " ";
  }
  return 0;
}