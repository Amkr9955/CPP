// inorder successor 0f bst

#include <bits/stdc++.h>

// int successor(TreeNode *root, int key)
// {
// if (root == NULL)
// return -1;
// int succ = -1;
// while (root != NULL)
//     {
//      if (key >= root->data)
//    {
//         root = root->right;        }
//         else
//         {
//        succ = root->data;
//             root = root->left;
//         }
//     }
//     return succ;
// }
// int pred(TreeNode *root, int key)
// {
//     if (root == NULL)
//         return -1;
//     int preds = -1;
//     while (root != NULL)
//     {
//         if (key > root->data)
//         {
//             preds = root->data;
//             root = root->right;
//         }
//         else
//         {
//             root = root->left;
//         }
//     }
//     return preds;
// }
// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {
//     if (root == NULL)
//         return {-1, -1};
//     return make_pair(pred(root, key), successor(root, key));
// }


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
   // Write your code here.
   int pred = -1; // Initializing predecessor to -1
   int succ = -1; // Initializing successor to -1
   TreeNode* temp = root; // Initializing a temporary pointer to root
   
   // Traversing the tree until either reaching the end or finding the key
   while(temp && temp->data != key) {  
       if(temp->data > key) {
           // If current node's data is greater than key, update successor and move to the left subtree
           succ = temp->data;
           temp = temp->left;
       }
       else {
           // If current node's data is less than or equal to key, update predecessor and move to the right subtree
           pred = temp->data;
           temp = temp->right;
       }
   }  
   
   // If key is found in the tree
   if(temp) {
       // Finding predecessor
       TreeNode* leftTree = temp->left;
       while(leftTree) {
           pred = leftTree->data;
           leftTree = leftTree->right;
       }
       // Finding successor
       TreeNode* rightTree = temp->right;
       while(rightTree) {
           succ = rightTree->data;
           rightTree = rightTree->left;
       }
   }
   
   // Return the pair containing predecessor and successor
   return {pred, succ};
}