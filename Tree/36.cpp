// Count Number of Nodes in a Binary Tree
// All levels except the last one are completely filled
// Last level nodes are as left as possible.
// If we get to know the height of the binary tree (say h), we can find out the maximum number of nodes 
// that can be present by the formula: 2^h – 1. 
// So there is some relation between height and number of nodes.

// If leftHeight == rightHeight, then the last level nodes are completely filled
// If leftHeight != rightHeight, then the last level nodes are not completely filled

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
    int leftheight(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int rightheight(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->right;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh=leftheight(root);
        int rh=rightheight(root);

        if(lh==rh) return (1<<lh)-1;

        int lrh=countNodes(root->left);
        int rrh=countNodes(root->right);

        return 1+lrh+rrh;
        
    }
};

// Time Complexity: O(log^2 N).

// Reason: To find the leftHeight and right Height we need only logN time and in the worst case 
// we will encounter the second case(leftHeight!=rightHeight) for at max logN times, so total time complexity will be O(log N * logN)

// Space Complexity: O(logN)

// Reason: Space is needed for the recursion stack when calculating height. As it is a complete tree, the height will always be logN.