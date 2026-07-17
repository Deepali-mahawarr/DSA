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
     int findheightleft(TreeNode*root){
       int h1=0;
       while(root){
        h1++;
        root=root->left;
       }
       return h1;
     }
      int findheightright(TreeNode*root){
       int h2=0;
       while(root){
        h2++;
        root=root->right;
       }
       return h2;
     }
    int countNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        int lh=findheightleft(root);
        int rh=findheightright(root);
        if(lh==rh)
        return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};
