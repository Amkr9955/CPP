//Recover Binary Search Tree
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
 * https://www.youtube.com/watch?v=ZWGW7FminDM&t=788s
 */
class Solution {
    private:
    TreeNode *prev,*first,*middle,*last;

    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        if(prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }

    public:
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first&&last) swap(first->val,last->val);
        else if(first and middle) swap(first->val,middle->val);

        
    }
};

// TC:O(N)
// SC:O(1) excluding auxialiary space