// https://www.youtube.com/watch?v=X0oXMdtUDwo
//largest bst in binary tree

#include<bits/stdc++.h>

class info{
public:
int maxi;
int mini;
bool isBST;
int size;
};
info solve(TreeNode *root, int &maxSize){
if(root == NULL){
return {INT_MIN, INT_MAX, true, 0};
}


info left = solve(root->left, maxSize);
info right = solve(root->right, maxSize);

info currNode;
currNode.size = left.size+right.size+1;
currNode.maxi = max(root->data, right.maxi);
currNode.mini = min(root->data, left.mini);

if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
currNode.isBST = true;
}
else{
currNode.isBST = false;
}

if(currNode.isBST){
maxSize = max(maxSize, currNode.size);
}
return currNode;
}
int largestBST(TreeNode * root){
int maxSize = 0;
info temp = solve(root, maxSize);
return maxSize;

}
