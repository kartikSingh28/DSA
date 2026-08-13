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