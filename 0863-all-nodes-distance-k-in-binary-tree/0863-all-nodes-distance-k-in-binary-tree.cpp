/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markpar(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*target){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(it->left!=nullptr){
            parent[it->left]=it;
            q.push(it->left);
        }
         if(it->right!=nullptr){
            parent[it->right]=it;
            q.push(it->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markpar(root,parent,target);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;

        int currleval=0;
        while(!q.empty()){
            int size=q.size();
        if(currleval==k)
        break;
        currleval++;
        for(int i=0;i<size;i++){
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left]=true;
            }
            if(curr->right && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right]=true;
            }
            if(parent[curr] && !vis[parent[curr]]){
                q.push(parent[curr]);
                vis[parent[curr]]=true;
            }
        }
        }
        vector<int>ans;
    while(!q.empty()){
        auto it=q.front();
        ans.push_back(it->val);
        q.pop();
    }
    return ans;
        
        
    }
};