class Solution {
public:
bool dfs(int node,int col,vector<int>&color,vector<vector<int>>& arr){
    color[node]=col;
    for(auto &it:arr[node]){
        if(color[it]==-1){
           if( dfs(it,!col,color,arr)==false)
           return false;
        }
        else if(color[it]==color[node])
        return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,arr)==false)
                return false;
            }
        }
        return true;

        
    }
};