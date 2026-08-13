//O(N) //BFS
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
vector<vector<int>> LevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root==nullptr)return ans;

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
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}


int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<vector<int>> res=LevelOrder(root);
    for(auto v:res){
        for(auto x:v){
            cout<<x<<" ";
        }
    }
    return 0;

}