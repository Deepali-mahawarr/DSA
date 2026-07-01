class Solution {
public:
// int solve(int ind,vector<int>&dp){
//     if(ind==0 || ind==1) return 1;
//     if(dp[ind]!=-1) return dp[ind];
//     int left=solve(ind-1,dp);
//     int right=INT_MAX;
//     if(right>1) 
//     right=solve(ind-2,dp);
//     // int mini=min(left,right);
//     dp[ind]=left+right;

//     return dp[ind];
// }
    // int climbStairs(int n) {
    //     vector<int>dp(n+1,0);
    //      dp[0]=1;
    //      dp[1]=1;
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];


    //     }
    //     return dp[n];
    // }
    int climbStairs(int n) {
       
         int prev1=1;
         int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;


        }
        return prev1;
    }
};