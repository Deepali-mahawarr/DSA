class Disjointset{
    public:
    vector<int>rank,parent,size;
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
            
        }
    }
    int findUpar(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionByrank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)
        return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
            
        }
    }
    void unionBysize(int u,int v){
         int ulp_u=findUpar(u);
         int ulp_v=findUpar(v);
         
         if(ulp_u==ulp_v) return ;
         if(size[ulp_u]< size[ulp_v]){
             parent[ulp_u]=ulp_v;
             size[ulp_v]+=size[ulp_u];
         }
         else {
             parent[ulp_v]=ulp_u;
             size[ulp_u]+=size[ulp_v];
         }
         
     }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        Disjointset ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[4]={0,0,-1,1};
                int dc[4]={1,-1,0,0};
                for(int k=0;k<4;k++){
                    int newr=row+dr[k];
                    int newc=col+dc[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int node=row*n+col;
                        int adjnode=newr*n+newc;
                        ds.unionBysize(node,adjnode);
                    }
                }
            }
        }
        int maxi=0;
         for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[4]={0,0,-1,1};
                int dc[4]={1,-1,0,0};
                set<int>componets;
                for(int k=0;k<4;k++){
                    int newr=row+dr[k];
                    int newc=col+dc[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                         int node=row*n+col;
                        int adjnode=newr*n+newc;
                        componets.insert(ds.findUpar(adjnode));
                    }
                }
                int totalsize=0;
                for(auto it:componets){
                    totalsize+=ds.size[it];
                }
                maxi=max(maxi,totalsize+1);
            }
         }
         
         for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findUpar(i)]);

         }
         return maxi;


        
    }
};