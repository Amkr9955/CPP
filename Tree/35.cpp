//Minimum time taken to burn the binary tree from a node
// https://www.youtube.com/watch?v=2r5wLmQfD6g

class Solution{
    public:
int findMaxDistance(map<TreeNode<int>*, TreeNode<int>*> &mpp, TreeNode<int>* target) {
    queue<TreeNode<int>*> q; 
    q.push(target); 
    map<TreeNode<int>*,int> vis; 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}

    TreeNode<int>* bfsToMapParents(TreeNode<int>* root,
    map<TreeNode<int>*,TreeNode<int>*> &parent,int start){
        TreeNode<int>* target;
        queue<TreeNode<int>*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode<int>* temp=q.front();
            if(temp->data==start){
                target=temp;
            }
            q.pop();
            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return target;
    }

    int timeToBurnTree(TreeNode<int>* root,int start){
        map<TreeNode<int>*,TreeNode<int>*>parent;
        TreeNode<int>* target=bfsToMapParents(root,parent,start);
        int time=findMaxDistance(parent,target);
        return time;
    }
    //TC:O(N+N)
    //SC:O(N) depending on how map works
}