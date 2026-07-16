/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode*root,vector<int>&ans,int leval){
    if(root==nullptr)
    return;
    if(ans.size()==leval)
    ans.push_back(root->val);
    solve(root->right,ans,leval+1);
    solve(root->left,ans,leval+1);
}

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int leval=0;
        solve(root,ans,leval);
        return ans;
        
    }
};