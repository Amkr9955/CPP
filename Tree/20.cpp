//Problem Statement: Given the root of a binary tree, return the zigzag level order traversal of Binary Tree. (i.e., from left to right, then right to left for the next level and alternate between).
//better approoch
//Initial Template for C++
#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int val;
  Node * left, * right;
};

vector<vector<int>>zigzagLevelOrder(Node* root){
    vector<vector<int>>result;
    if(root==NULL){
        return result;
    }
    queue<Node*>q;
    q.push(root);
    bool leftToRight=true;

    while(!q.empty()){
        int size=q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
            Node *node=q.front();
            q.pop();
            int index=(leftToRight) ? i:(size-1-i);
            row[index]=node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        leftToRight=!leftToRight;
        result.push_back(row);
    }
    return result;
    
}

Node * newNode(int data) {
  Node * node = new Node;
  node -> val = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
int main() {
  int i, j;
  Node * root = newNode(3);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);
  vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for (i = 0; i < ans.size(); i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
//TC:O(N)
//SC:O(N)