//https://www.youtube.com/watch?v=KabDfyPUgcY
// Input : Delete 20 in below tree
//        10
//      /    \         
//  20     30
//             \
//             40

// Output:    
//        10
//    /      \             
// 40        30

// 1.Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete. 
// 2.Replace the deepest rightmost node’s data with the node to be deleted. 
// 3.Then delete the deepest rightmost node.

//first approach:bfs but well have to do 2 bfs which gives runtime error
//https://www.geeksforgeeks.org/deletion-binary-tree/

// To avoid the above error and also to avoid doing BFS twice (1st iteration while searching the rightmost deepest node, and 2nd while deleting the rightmost deepest node),
// we can store the parent node while first traversal and after setting the rightmost deepest node’s data to the node needed deletion, easily delete the rightmost deepest node.

#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->data << " "; 
    inorder(temp->right); 
} 

struct Node* deletion(struct Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        if(root->data==key){
            delete (root);
            return NULL;
        }
        else{
            return root;
        }
    }
    Node *lastparent;
    Node *temp;
    Node *keynode=NULL;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
      temp=q.front();
      q.pop();
      if(temp->data==key){
        keynode=temp;
      }
      if(temp->left){
        lastparent=temp;
        q.push(temp->left);
      }
      if(temp->right){
        lastparent=temp;
        q.push(temp->right);
      }
      }
      

      if(keynode!=NULL){
        keynode->data=temp->data;
      
      if(lastparent->right==temp){
        lastparent->right=NULL;
      }
      else{
        lastparent->left=NULL; 
      }
      delete (temp);
      }
      return root;
}

int main() 
{ 
    struct Node* root = newNode(9); 
    root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->right = newNode(7); 
    root->right = newNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 7; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
  
    return 0; 
}  
