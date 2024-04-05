//Two sum in BST
//BFS
class Solution {
public:
    bool find(TreeNode* root, int target, TreeNode* curr) {
        if(root == nullptr) return false;
                
        if(root != curr && root->val == target) return true;
        
		return find(root->left, target, curr) || find(root->right, target, curr);
    }
    
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0 ; i<n ; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                bool isPresent = find(root, k - node->val, node);
                
                if(isPresent) return true;
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return false;
    }
};
//DFS
/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/
bool dfs(unordered_map<int,int> &mp,BinaryTreeNode* root,int k){
        if(root==NULL){
            return false;
        }
        if(mp.find(k-root->val)!=mp.end())return true;
        mp[root->val]++;
        return dfs(mp,root->left,k)||dfs(mp,root->right,k);
    }
bool pairSumBst(BinaryTreeNode *root, int k)
{
      if(root==NULL){
            return false;
        }
        unordered_map<int,int>mp;
        return dfs(mp,root,k);
        
    // Write your code here
}