class Solution {
public:
// int solve(int ind,vector<int>&nums,vector<int>&dp)
// {   int maxi=INT_MIN;
//     if(ind==0) return nums[ind];
//     if(ind<0) return 0;
//     if(dp[ind]!=-1) return dp[ind];
//     int pick=nums[ind]+solve(ind-2,nums,dp);
//     int notpick=0+solve(ind-1,nums,dp);
//     return dp[ind]=max(pick,notpick);
    
// }    
// int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,-1);
//         return solve(n-1,nums,dp);
        
//     }
//  int rob(vector<int>& nums) {
//          int n=nums.size();
//      vector<int>dp(n,0);
//       dp[0]=nums[0];

//      for(int i=1;i<n;i++){
//         int pick=nums[i];
//         if(i>1) pick=nums[i]+dp[i-2];
//         int notpick=0+dp[i-1];
//         dp[i]=max(pick,notpick);

//      }
//      return dp[n-1];
//  }
int rob(vector<int>& nums) {
    int n=nums.size();
   
    int prev1=nums[0];
    int prev2=0;

     for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick=nums[i]+prev2;
        int notpick=0+prev1;
       

        int curr=max(pick,notpick);
        prev2=prev1;
        prev1=curr;
     }
        return prev1;


}
     
};