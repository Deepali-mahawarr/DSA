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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans=0;
        queue<pair<TreeNode*,long long >>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            auto it=q.front();
            
            int mini=it.second;
            int first;
            int last;
            for(int i=0;i<size;i++){
                long long currid=q.front().second-mini;
                TreeNode*node=q.front().first;
                q.pop();
                if(i==0) first=currid;
                if(i==size-1) last=currid;
                if(node->left!=nullptr)
                q.push({node->left,currid*2+1});
                if(node->right!=nullptr)
                q.push({node->right,currid*2+2});
            }
            ans=max(ans,last-first+1);

        }
        return ans;
        
    }
};