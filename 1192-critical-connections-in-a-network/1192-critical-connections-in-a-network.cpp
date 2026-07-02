class Solution {
    private: 
    int timer=1;
    private:
    void dfs(int node,int parent,vector<int>&vis, vector<vector<int>>&adj,vector<int>&tin,vector<int>&low, vector<vector<int>>&bridge){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto &it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,tin,low,bridge);
                low[node]=min(low[node],low[it]);
                //if it bridge
                if(low[it]>tin[node])
                bridge.push_back({it,node});

            }
            else{
                 low[node]=min(low[node],low[it]);

            }

        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>&nums) {
        vector<vector<int>>adj(n);
        for(auto it:nums){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>bridge;
        dfs(0,-1,vis,adj,tin,low,bridge);
        return bridge;
        
    }
};