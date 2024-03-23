//floor value in biary search tree
#include <bits/stdc++.h>

using namespace std;

//Declaring the struct for Tree implementation.
struct node
{
    int data;
    struct node *left, *right;
};

//Defining a function for inserting new-node in BST
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int findFloor(node *root, int input)
{

   int floor=-1;
   while(root!=NULL){
    if(root->data==input){
        return root->data;
    }
    else if(root->data<input){
        floor=root->data;
        root=root->right;
    }
    else{
        
        root=root->left;

    }
   }
   return floor;
    
  
}

int main()
{
    // Driver Code.
    struct node *root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->left->right->right = newNode(8);
    root->right = newNode(11);

    cout << findFloor(root, 6);
    cout << endl;

    return 0;
}


// Time Complexity: O(log(N)) {Similar to Binary Search, at a given time we’re searching one half of the tree, so the time taken would be of the order log(N) where N are the total nodes in the BST and log(N) is the height of the tree.}

// Space Complexity: O(1) {As no extra space is being used, we’re just traversing the BST.}