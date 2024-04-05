//Kth smallest element in bst
//we can use inorder traversal as it sorts in 
class Solution {
public:
    int ans;
    void kans(TreeNode* root,int k,int &idx){
        if(!root){
            return;
        }
        kans(root->left,k,idx);
        if(idx==k){
            ans=root->val;
            idx++;
            return;
        }
        if (idx>k) {
        return;
    } 
        else{
            idx++;
        }
        kans(root->right,k,idx);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int idx=1;
        ans=-1;
        kans(root,k,idx);
        return ans;
        
    }
};
// TC:O(k)

// kth largest
 void kans(TreeNode* root,int k,int &idx){
        if(!root){
            return;
        }
        kans(root->right,k,idx);
        if(idx==k){
            ans=root->val;
            idx++;
            return;
        }
        if (idx>k) {
        return;
    } 
        else{
            idx++;
        }
        kans(root->left,k,idx);
    }