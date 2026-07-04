class Solution {
public:
      int solve(int ind,vector<int>&coins,int sum,vector<vector<int>>&dp){
        int n=coins.size();
        if(sum==0) return 0;
       if(ind==0){
        if(sum%coins[ind]==0) return sum/coins[ind];
        else
        return 1e9;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        int pick=1e9;
        if(coins[ind]<=sum)
        pick=1+solve(ind,coins,sum-coins[ind],dp);
        int notpick=solve(ind-1,coins,sum,dp);
        return dp[ind][sum]= min(pick,notpick);

      }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans; 
        
    }
};