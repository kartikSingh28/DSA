#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left,*right;
    TreeNode(int x){
        data=x;
        left=right=nullptr;
    }
};

void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track,TreeNode* target){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right]=curr;
            q.push(curr->right);
        }
    }

}
vector<int> distanceK(TreeNode* root,TreeNode* target,int k){
    unordered_map<TreeNode* ,TreeNode*> parent_track;
    markParents(root,parent_track,target);
    unordered_map<TreeNode*,bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!q.empty()){
        int sz=q.size();
        if(curr_level++==k)break;
        for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left &&!visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right &&!visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
        }
    }
    vector<int> res;
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        res.push_back(node->data);
    }
    return res;
}


int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right=new TreeNode(5);
    return 0;
}