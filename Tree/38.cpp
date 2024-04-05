// construct a binary tree from inorder and postorder traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd,map<int,int> &mp){
        if(inStart>inEnd||postStart>postEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int elem=mp[root->val];
        int leftlength=elem-inStart;
        root->left=buildTree(inorder,postorder,inStart,elem-1,postStart,postStart+leftlength-1,mp);
        root->right=buildTree(inorder,postorder,elem+1,inEnd,postStart+leftlength,postEnd-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart=0,inEnd=inorder.size()-1;
        int postStart=0,postEnd=postorder.size()-1;
        map<int,int>mp;
        for(int i=inStart;i<=inEnd;i++){
            mp[inorder[i]]=i;
        }
        return buildTree(inorder,postorder,inStart,inEnd,postStart,postEnd,mp);
        
    }
};

// TC:O(N)
// SC:O(N)