//valid bst or not
class Solution {
public:
    bool isValid(TreeNode* root,long long l,long long r){
        if(root==NULL)
        return true;
        if(root->val>l and root->val<r){
           return isValid(root->left,l,root->val) && isValid(root->right,root->val,r);
            
        }
        return false;
    }

    
    bool isValidBST(TreeNode* root) {
        long long int l=-10000000000,r=10000000000;
        return isValid(root,l,r);
    
    }
};
// TC:O(N)
// SC:O(1)