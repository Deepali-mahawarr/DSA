// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//        vector<vector<pair<int,int>>> adj(n);

//         for(auto &it:roads){
//             adj[it[0]].push_back({it[1],it[2]});
//             adj[it[1]].push_back({it[0],it[2]});

//         }
//         priority_queue<
//         pair<long long,int>,
//         vector<pair<long long,int>>,
//         greater<pair<long long,int>>>pq;
//         vector<long long>dist(n,LLONG_MAX);
//         vector<int>ways(n,0);
//         dist[0]=0;
//     ways[0]=1;
//     int mod=(int)(1e9+7);
//     pq.push({0,0});
//     while(!pq.empty()){
//         int node=pq.top().second;
//         int dis=pq.top().first;
//         pq.pop();
//         if (dis > dist[node]) continue;
//         for(auto &it:adj[node]){
//             int adjNode=it.first;
//             long long edw=it.second;
//             if(dis+edw < dist[adjNode]){
//                 dist[adjNode]=dis+edw;
//                 pq.push({dis+edw,adjNode});
//                 ways[adjNode]=ways[node];

//             }
//             else if(dis+edw==dist[adjNode]){
//                 ways[adjNode]=(ways[adjNode]+ways[node])%mod;
//             }
//         }
//     }
//     return ways[n-1];
        
//     }
// };
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        vector<long long >dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(int)1e9+7;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            long long  dis=it.first;
           // if(dis >dist[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgewt=it.second;
                if(dis+edgewt <dist[adjnode]){
                    dist[adjnode]=dis+edgewt;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis+edgewt==dist[adjnode])
                ways[adjnode]=(ways[node]+ways[adjnode])%mod;
            }
        }
        return ways[n-1]%mod;

        
    }
};
