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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);

        }
        Disjointset ds(maxrow+maxcol+1);
        unordered_map<int,int>mpp;
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionBysize(noderow,nodecol);
            mpp[noderow]=1;
            mpp[nodecol]=1;

        }
        int cnt=0;
        for(auto it:mpp){
            if(ds.findUpar(it.first)==it.first){
                cnt++;
            }
        }
        return (n-cnt);
        
    }
};