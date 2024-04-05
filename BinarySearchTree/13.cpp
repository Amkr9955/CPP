//merge two BST
/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
#include<bits/stdc++.h>

class BSTIterator{
    public:
    stack<TreeNode*>st;

    BSTIterator(TreeNode* root){
        pushAll(root);
    }
    
    bool hasNext(){
        return !st.empty();
    }
    int peek() {
    return st.top()->data;  // Return the value of the top element without removing it
  }
    int next(){
        TreeNode* node=st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }
    void pushAll(TreeNode* root){
        for(;root!=NULL;root=root->left){
            st.push(root);
        }
    }
};
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    BSTIterator itr1(root1);
    BSTIterator itr2(root2);
    vector<int>ans;
  while (itr1.hasNext() || itr2.hasNext()) {
    // Check for both iterators and add the smaller element
    if (itr1.hasNext() && itr2.hasNext()) {
      int val1 = itr1.peek();
      int val2 = itr2.peek();
      if (val1 < val2) {
        ans.push_back(itr1.next());
      } else {
        ans.push_back(itr2.next());
      }
    } else if (itr1.hasNext()) {
      ans.push_back(itr1.next());
    } else {
      ans.push_back(itr2.next());
    }
  }

  return ans;
}
// TC:O(M+N)
// SC:O(h1+h2)