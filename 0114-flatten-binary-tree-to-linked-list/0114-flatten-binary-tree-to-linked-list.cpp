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
 void flatten(TreeNode* root) {
    TreeNode*curr=root;
    while(curr!=nullptr){
        if(curr->left!=nullptr){
            TreeNode*prev=curr->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left = nullptr;  

        }
        curr=curr->right;
    }
 }

    // void flatten(TreeNode* root) {
    //      if(root == nullptr) return;
    //     stack<TreeNode*>st;
    // st.push(root);
    //     while(!st.empty()){
    //         TreeNode* curr=st.top();
    //         st.pop();
    //         if(curr->right)
    //         st.push(curr->right);
    //         if(curr->left)
    //         st.push(curr->left);
    //         if(!st.empty()){
    //             curr->right=st.top();
    //         }
    //             curr->left=nullptr;

        

    //     }


        
    // }
};