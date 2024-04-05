// construct bst from given preorder traversal
// https://www.youtube.com/watch?v=UmJT3j26t1I


class Solution {
public:
    TreeNode* build(vector<int>& preorder,int &i,int bound){
        if(i==preorder.size()||preorder[i]>bound)
        return NULL;
        TreeNode *root=new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};
// TC:O(3*N)==O(N)
// SC:O(N)