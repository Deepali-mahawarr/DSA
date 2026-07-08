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
int findsum(TreeNode* root,int &path){
    if(root==nullptr)
  // if(root->left==nullptr && root->right==nullptr)
    return 0;
    
    int lh=max(0,findsum(root->left,path));
    int rh=max(0,findsum(root->right,path));
    path=max(path,lh+rh+root->val);
    return max(lh,rh)+root->val;
}
    int maxPathSum(TreeNode* root) {
        int path=INT_MIN;
        findsum(root,path);
        return path;
        
    }
};