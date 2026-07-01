class Solution {
public:
int solve(int ind,vector<int>&dp){
    if(ind==0 || ind==1) return 1;
    if(dp[ind]!=-1) return dp[ind];
    int left=solve(ind-1,dp);
    int right=INT_MAX;
    if(right>1) 
    right=solve(ind-2,dp);
    // int mini=min(left,right);
    dp[ind]=left+right;

    return dp[ind];
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};