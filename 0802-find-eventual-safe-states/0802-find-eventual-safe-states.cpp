class Solution {
public:
 bool dfs(int node,vector<vector<int>>&arr,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
      vis[node]=1;
      pathvis[node]=1;
      check[node]=0;

      
      for(auto it:arr[node]){
          if(!vis[it]){
             if(dfs(it,arr,vis,pathvis,check)==true){
             check[node]=0;
             return true;
             }
          }
          else if(pathvis[it]){
          check[node]=0;

          return true;
          }
      }
      check[node]=1;
      pathvis[node]=0;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& arr) {
        int V=arr.size();
         vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,arr,vis,pathvis,check);
            }
        }
        vector<int>safenode;
       for(int i=0;i<V;i++){
        if(check[i]==1){
            safenode.push_back(i);
        }

       }
       return safenode;
        
    }
};