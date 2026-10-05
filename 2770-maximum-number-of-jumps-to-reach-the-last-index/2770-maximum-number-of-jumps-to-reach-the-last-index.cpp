class Solution {
public:
    int solve(int ind,int target,vector<int>& nums,vector<int>&dp){
        int n=nums.size();
        
        if(ind==n-1)
        return 0;
        if(dp[ind]!=0)
        return dp[ind];
        int ans=-1;
        for(int k=ind+1;k<n ;k++){
        if(abs(nums[k]-nums[ind])<=target){
            int res = solve(k, target, nums,dp);
            if (res != -1) {
                    ans= max(ans, 1 + res);
                    
                }
                
        }
}
        return dp[ind]=ans;
 }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,0);
          return solve(0,target,nums,dp);
        
    }
};