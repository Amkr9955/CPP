//calculate diameter of binary tree Approach 1(worst)
//Problem Statement: Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int data);

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct node* node);

int diameter(struct node* root)
{
   if(root==NULL)
   return 0;

   int lh=height(root->left);
   int rh=height(root->right);

   int ld=diameter(root->left);
   int rd=diameter(root->right);
   
   return max(lh+rh+1,max(ld,rd));
	
}

int height(struct node* root){
    if(root==NULL)
    return 0;

    return max(height(root->left),height(root->right))+1;
}

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{

	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	
	cout << "Diameter of the given binary tree is "
		<< diameter(root)<<endl;;

	return 0;
}

//TC:O(N*N)
//SC:O(N) for call stack


