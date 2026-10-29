/*
Maximum Depth of Binary Tree (LC 104), DFS version
Return the number of nodes on the longest path from the root down to a leaf.
Example: [1,2,3,4,5] -> 3
*/
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
int maxDepth(TreeNode* root){
    if(root==nullptr) return 0;

    int leftTree=maxDepth(root->left);
    int rightTree=maxDepth(root->right);

    return 1+max(leftTree,rightTree);
}

int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right=new TreeNode(5);
    int res=maxDepth(root);
    cout<<res<<" ";
    return 0;

}