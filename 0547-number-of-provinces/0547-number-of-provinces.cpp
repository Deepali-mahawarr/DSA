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
    int findupar(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v)
        return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
            
        }
    }
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
       int ulp_v=findupar(v);
        if(ulp_u==ulp_v)
        return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        Disjointset ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]==1){
                    ds.unionbysize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if( ds.findupar(i)==i)
            cnt++;
            
        }
return cnt;
        
    }
};