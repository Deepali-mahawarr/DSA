// class Solution {
// public:
// int f(int ind,int jump,vector<int>&nums,vector<vector<int>>&dp){
//     int n=nums.size();
//     int mini=INT_MAX;
//     if(ind>=n-1)
//     return jump;
//     if(dp[ind][jump]!=-1)
//     return dp[ind][jump];
//     for(int i=1;i<=nums[ind];i++){
//         mini=min(mini,f(ind+i,jump+1,nums,dp));
//     }
//     return dp[ind][jump]= mini;

// }
// int jump(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return f(0,0,nums,dp);

        
//     }
// };
 class Solution{
    public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        long long  jump=0;
        int l=0;
        int r=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);


            }
            jump++;
            l=r+1;
            r=farthest;
        }
        return jump;
    }
 };