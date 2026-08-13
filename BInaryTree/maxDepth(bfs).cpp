//max depth of a binary tree
//just count the no levels in level order Traversal
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
    if(root==nullptr) return -1;
    int count =0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        vector<int> level;
        for(int i=0;i<sz;i++){
            TreeNode* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }if(node->right){
                q.push(node->right);
            }
        }
        count++;
    }

    return count;
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