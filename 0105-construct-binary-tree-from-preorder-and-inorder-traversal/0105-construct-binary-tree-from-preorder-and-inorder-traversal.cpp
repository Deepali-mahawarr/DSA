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
TreeNode* findtree(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int>&inmpp){
    if(ps>pe || is>ie) return 0;
    TreeNode* root=new TreeNode(preorder[ps]);
    int inroot=inmpp[root->val];
    int numsleft=inroot-is;
    root->left=findtree(preorder,ps+1,ps+numsleft,inorder,is,inroot-1,inmpp);
    root->right=findtree(preorder,ps+numsleft+1,pe,inorder,inroot+1,ie,inmpp);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inmpp;
        for(int i=0;i<inorder.size();i++){
            inmpp[inorder[i]]=i;
        }
        TreeNode*root=findtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmpp);
        return root;
        
    }
};