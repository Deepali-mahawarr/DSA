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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>leval(size);
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int ind=(lefttoright) ? i:(size-1-i);
                
                     if(it->left!=nullptr)
                        q.push(it->left);

                     if(it->right!=nullptr)
                        q.push(it->right);
                
                leval[ind]=it->val;
}
            lefttoright=!lefttoright;
        ans.push_back(leval);


        }
        return ans;

        
    }
};
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root==NULL) return ans;
//         queue<TreeNode*> q;
//         q.push(root);
//         bool sign=false;

//         while(!q.empty()){
//             int n=q.size();
//             vector<int> temp(n);
//             for(int i=0;i<n;i++){
//                 TreeNode* node=q.front();
//                 q.pop();
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//                 if(sign) temp[n-1-i]=node->val;
//                 else temp[i]=node->val;
//             }

//             sign=!sign;
//             ans.push_back(temp);
//         }

//         return ans;
//     }
// };