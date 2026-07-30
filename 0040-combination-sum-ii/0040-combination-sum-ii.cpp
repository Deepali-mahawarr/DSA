class Solution {
public:
void solve(int ind,int target,vector<int>& nums,vector<int>&ds, vector<vector<int>>&ans){
    int n=nums.size();

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
for(int i=ind;i<n;i++){
    if(i>ind && nums[i]==nums[i-1])
    continue;
    if(nums[i]>target) break;
    ds.push_back(nums[i]);
    solve(i+1,target-nums[i],nums,ds,ans);
    ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>&nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        solve(0,target,nums,ds,ans);
        return ans; 
        
    } 
};