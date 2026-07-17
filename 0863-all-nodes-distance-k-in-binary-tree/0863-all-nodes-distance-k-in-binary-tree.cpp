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
void markpar(TreeNode*root,  unordered_map<TreeNode*,TreeNode*>&parent){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(it->left){
            q.push(it->left);
            parent[it->left]=it;
        }
        if(it->right){
            q.push(it->right);
            parent[it->right]=it;
        }
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markpar(root,parent);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int currleval=0;
        while(!q.empty()){
            int size=q.size();
            if(currleval==k) break;
            currleval++;
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                if(it->left!=nullptr && !vis[it->left]){
                    q.push(it->left);
                    vis[it->left]=true;
                }
                if(it->right!=nullptr && !vis[it->right]){
                    q.push(it->right);
                    vis[it->right]=true;
                }
                if(parent[it] && !vis[parent[it]]){
                    q.push(parent[it]);
                    vis[parent[it]]=true;
                }
            }            
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};