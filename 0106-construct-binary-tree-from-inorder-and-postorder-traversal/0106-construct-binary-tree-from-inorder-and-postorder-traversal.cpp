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
TreeNode* findtree(vector<int>&postorder,int ps,int pe,vector<int>&inorder,int is,int ie,  map<int,int>&inmpp){
   
    if (ps>pe || is>ie)
    return 0;
TreeNode*root=new TreeNode(postorder[pe]);
int inroot=inmpp[root->val];
int numleft=inroot-is;
root->left=findtree(postorder,ps,ps+numleft-1,inorder,is,inroot-1,inmpp);
root->right=findtree(postorder,ps+numleft,pe-1,inorder,inroot+1,ie,inmpp);
return root;

}


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inmpp;
        for(int i=0;i<inorder.size();i++){
            inmpp[inorder[i]]=i;

        }
        TreeNode*root=findtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inmpp);
        return root;
        
    }
};