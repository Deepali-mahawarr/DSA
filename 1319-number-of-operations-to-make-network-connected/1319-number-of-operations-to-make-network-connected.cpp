class Disjointset{
   
    vector<int>rank,parent,size;
    public:
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
    int makeConnected(int n, vector<vector<int>>& edge) {
        Disjointset ds(n);
            int cntextra=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v))
            cntextra++;
            else 
            ds.unionBysize(u,v);

        }
        int totalcomponent=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i)
            totalcomponent++;
        }
        int needed=totalcomponent-1;
        if(cntextra>=needed){
            return needed;
        }
        return -1;
        
        
    }
};