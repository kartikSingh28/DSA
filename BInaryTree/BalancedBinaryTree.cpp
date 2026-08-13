// a binary tree is balanced if leftsubtree-rightSubtree <=1
//patern dfs height
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
int isBalanced(TreeNode* root){
    if(root==nullptr) return 0;

    int left=isBalanced(root->left);
    if(left==-1){
        return -1;
    }
    int right=isBalanced(root->right);
    if(right==-1){
        return -1;
    }
    if(abs(left-right)>1){
        return -1;
    }
    return 1+max(left,right);
}

int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right=new TreeNode(5);
    if(isBalanced(root)!=-1){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced";
    }
    return 0;

}