// Inorder Traversal using Stack

// 1.Create an empty stack (say S).
// 2.Initialize the current node as root.
// 3.Push the current node to S and set current = current->left until current is NULL
// 4.If current is NULL and the stack is not empty then:
//     a.Pop the top item from the stack.
//     b.Print the popped item and set current = popped_item->right 
//     c.Go to step 3.
// 5.If current is NULL and the stack is empty then we are done.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void inOrder(struct Node* &root){
    stack<Node*>st;
    while(root!=NULL||!st.empty()){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
}

int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<"Inorder Traversal using Stack \n";
    inOrder(root);

    return 0;
}


