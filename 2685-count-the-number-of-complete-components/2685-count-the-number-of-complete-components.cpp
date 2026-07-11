class Solution {
public:
//     void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& nodes, int& degSum) {
//         vis[node]=1;
//         nodes++;
//         degSum+=adj[node].size();
//         for(int nei:adj[node]){
//             if(!vis[nei])
//                 dfs(nei,adj,vis,nodes,degSum);
//         }
//     }
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for(auto &e:edges){
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }
//         vector<int> vis(n,0);
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 int nodes=0,degSum=0;
//                 dfs(i,adj,vis,nodes,degSum);
//                 int edgeCount=degSum/2;
//                 if(edgeCount==nodes*(nodes-1)/2) ans++;
//             }
//         }
//         return ans;
//     }





    void dfs(int node,int &totalnode,int &degsum,  vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        totalnode++;
        degsum+=adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,totalnode,degsum,adj,vis);
            }

        }
    }
int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int totalnode=0;
                int degsum=0;
                dfs(i,totalnode,degsum,adj,vis);
                int edgecnt=degsum/2;
                if(edgecnt==(totalnode*(totalnode-1))/2)
                ans++;
            }
        }
        return ans;
     }

};