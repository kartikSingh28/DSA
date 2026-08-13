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
bool isLeaf(TreeNode* root){
    if(root==nullptr)return false;
    if(root->left==nullptr && root->right==nullptr){
        return true;
    }
    return false;
}

void addLeftBoundary(TreeNode* root,vector<int> &res){
    if(root==nullptr) return;
    TreeNode* curr=root->left;
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }else{
            curr=curr->right;
        }
        
    }
}
void addLeaves(TreeNode* root,vector<int> &res){
    if(root==nullptr){
        return;
    }
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    addLeaves(root->left,res);
    addLeaves(root->right,res);
}

void addRightBoundary(TreeNode* root,vector<int> &res){
    vector<int> temp;
    TreeNode* curr=root->right;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
            
        }
        if(curr->right){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
void BoundaryTraversal(TreeNode* root){
    if(root==nullptr)return;
    vector<int> res;
    if(!isLeaf(root)){
        res.push_back(root->data);
    }
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    for(auto x:res){
        cout<<x<<" ";
    }
}

int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right=new TreeNode(5);
    BoundaryTraversal(root);
    return 0;
}