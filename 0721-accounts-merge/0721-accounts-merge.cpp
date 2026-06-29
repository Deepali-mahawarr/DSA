// User function Template for C++
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& nums) {
        int n=nums.size();
        //int m=nums[0].size();
Disjointset ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<nums[i].size();j++){
                string mail=nums[i][j];
                if(mpp.find(mail)==mpp.end())
                mpp[mail]=i;
                else
                ds.unionBysize(i,mpp[mail]);
            }
        }
vector<vector<string>>idxmpp(n);
for(auto it:mpp){
    int idx=(it.second);
    string mail=it.first;
    int node=ds.findUpar(idx);
    idxmpp[node].push_back(mail);
}
vector<vector<string>>ans;
for(int i=0;i<n;i++){
    if(idxmpp[i].size()==0) continue;
    sort(idxmpp[i].begin(),idxmpp[i].end());
    vector<string>temp;
    temp.push_back(nums[i][0]);
    for(auto it:idxmpp[i]){
        temp.push_back(it);
    }
    ans.push_back(temp);
}
return ans;
       
    }
};