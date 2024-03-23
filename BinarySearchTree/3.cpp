//delete node from BST

#include <iostream>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;    
    
    // Pointer to the left child node
    TreeNode* left; 
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    TreeNode* deleteNode(TreeNode* root,int key){
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root!=NULL){
            if(key<root->val){
                if(root->left!=NULL&&root->left->val==key){
                    root->left=helper(root->left);
                }
                else{
                    root=root->left;
                }
            }
            else{
                 if(root->right!=NULL&&root->right->val==key){
                    root->right=helper(root->right);
                }
                else{
                    root=root->right;
                }

            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        //only one child or no child
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else{//two child //check striver solution
            TreeNode* rightChild=root->right;
            TreeNode* lastRight=findLastRight(root->left);
            lastRight->right=rightChild;
        }
        return root->left;
    }
    
    TreeNode* findLastRight(TreeNode* root){
         if(root->right==NULL){
            return root;
         }
         return findLastRight(root->right);
    }

};

// Function to perform an in-order traversal

void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return; 
    }

    printInOrder(root->left);

    cout << root->val << " ";

    printInOrder(root->right);
}


int main() {
    Solution solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Printing the original tree
    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    // Testing the deleteNode function
    int keyToDelete = 3;
    TreeNode* updatedTree = solution.deleteNode(root, keyToDelete);
    // Printing the tree after deletion
    cout << "Tree After Deletion (Inorder Traversal): ";
    printInOrder(updatedTree);
    cout << endl;

    return 0;
}