class Disjoint{
  public:  
    vector<int> rank, par,size;
    
    public:
       Disjoint(int n){
           rank.resize(n+1,0);
           size.resize(n+1,0);
           par.resize(n+1,0);
           for(int i=0;i<=n;i++) {
               par[i]=i;
               size[i]=1;
           }
       }
       
       int findUpar(int node){
           if(par[node]==node) return node;
           
           return par[node]=findUpar(par[node]);
       }
       
       void UnionByRank(int u, int v){
           int up_u= findUpar(u);
           int up_v= findUpar(v);
           
           if(up_u == up_v) return ;
           if(rank[up_u] < rank[up_v]) par[up_u]=up_v;
           else if(rank[up_u] > rank[up_v]) par[up_v]= up_u;
           else {
               par[up_v]=up_u;
               rank[up_u]++;
           }
       }
       
       void UnionBySize(int u, int v){
           int up_u= findUpar(u);
           int up_v= findUpar(v);
           
           if(up_u == up_v) return;
           
           if( size[up_u] < size[up_v]){
               par[up_u]=up_v;
               size[up_v]+=size[up_u];
           }
           else{
               par[up_v]=up_u;
               size[up_u]+=size[up_v];
           }
       }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n*n);
        vector<pair<int,pair<int,int>>> temp;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back({grid[i][j],{i,j}});
            }
        }

        sort(temp.begin(),temp.end());

        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        for(auto it: temp){
           int t=it.first;
           int r=it.second.first;
           int c=it.second.second;
           int node=r*n+c;
           vis[r][c]=1;
           for(int i=0;i<4;i++){
              int nrow=r+drow[i];
              int ncol=c+dcol[i];

              if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]){
                int adjnode=nrow*n+ncol;
                ds.UnionByRank(node,adjnode);
              }
           }

           if(ds.findUpar(0)==ds.findUpar(n*n-1)) return t;
        }

        return -1;
    }
};