class Solution {
public:
int solve(int ind,int previdx,vector<int>&nums, vector<vector<int>>&dp){
    int n=nums.size();
    if(ind==n) return 0;
    if(dp[ind][previdx+1]!=-1) return dp[ind][previdx+1];
    int len =0+solve(ind+1,previdx,nums,dp);
    if(previdx==-1 || nums[ind]>nums[previdx]){
        len=max(len,1+solve(ind+1,ind,nums,dp));
    }
    return dp[ind][previdx+1]=len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
        
    }
};