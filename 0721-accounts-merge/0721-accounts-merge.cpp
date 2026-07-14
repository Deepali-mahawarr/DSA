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
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n=arr.size();
        Disjointset ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<(int)arr[i].size();j++){
                string mail=arr[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    ds.unionBysize(i,mpp[mail]);
                }
            }
        }
        vector<vector<string>>mailnode(n);
        for(auto it:mpp){
            string mail_id=it.first;
            int node=ds.findUpar(it.second);
            mailnode[node].push_back(mail_id);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mailnode[i].size()==0) continue;
            sort(mailnode[i].begin(),mailnode[i].end());
            vector<string>temp;
            temp.push_back(arr[i][0]);
            for(auto it:mailnode[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;


        
    }
};