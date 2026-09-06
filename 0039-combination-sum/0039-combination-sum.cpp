class Solution {
public:
  void solve(int ind,vector<int>&ds, vector<vector<int>>&ans, vector<int>&arr,int target){
    int n=arr.size();
    if(target==0){
        ans.push_back(ds);
        return;
    }
    if(ind==n){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[ind]<=target){
    ds.push_back(arr[ind]);
    solve(ind,ds,ans,arr,target-arr[ind]);
    ds.pop_back();
    }
    solve(ind+1,ds,ans,arr,target);
}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,ds,ans,arr,target);
        return ans;
        
    }
};