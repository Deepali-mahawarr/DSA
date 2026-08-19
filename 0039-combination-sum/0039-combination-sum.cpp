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
        if(nums[ind]<=target){
        ds.push_back(nums[ind]);
        solve(ind,target-nums[ind],nums,ds,ans);
        ds.pop_back();
        }
        solve(ind+1,target,nums,ds,ans);
     

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,nums,ds,ans);
        return ans; 
    }
};