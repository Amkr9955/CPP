//calculate diameter of binary tree Approach 2(better)
//Problem Statement: Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int data);

int max(int a, int b) { return (a > b) ? a : b; }


int height(struct node* root,int &dia)
{
   if(root==NULL)
   return 0;

   int ld=height(root->left,dia);
   int rd=height(root->right,dia);

   dia=max(ld+rd,dia);

   return max(ld,rd)+1;
	
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
    int diameter=0;
    height(root,diameter);

	
	cout << "Diameter of the given binary tree is "<< diameter <<endl;

	return 0;
}

//TC:O(N)
//SC:O(N) for call stack


