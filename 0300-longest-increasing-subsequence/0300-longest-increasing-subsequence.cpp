class Solution {
public:
// int solve(int ind,int previdx,vector<int>&nums, vector<vector<int>>&dp){
//     int n=nums.size();
//     if(ind==n) return 0;
//     if(dp[ind][previdx+1]!=-1) return dp[ind][previdx+1];
//     int len =0+solve(ind+1,previdx,nums,dp);
//     if(previdx==-1 || nums[ind]>nums[previdx]){
//         len=max(len,1+solve(ind+1,ind,nums,dp));
//     }
//     return dp[ind][previdx+1]=len;
// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(0,-1,nums,dp);
        
//     }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prevind=ind-1;prevind>=-1;prevind--){
    //             int len=0+dp[ind+1][prevind+1];
    //             if(prevind==-1 || nums[ind]>nums[prevind]){
    //                 len=max(len,1+dp[ind+1][ind+1]);
    //             }
    //             dp[ind][prevind+1]=len;
                
    //         }
    //     }
    //     return dp[0][0];
    // }



    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     int maxi=0;
    //     vector<int>dp(n,1);
    //     for(int i=0;i<n;i++){
    //         for(int prev=0;prev<i;prev++){
    //             if(nums[prev]<nums[i]){
    //                 dp[i]=max(dp[i],1+dp[prev]);
    //             }

    //         }
    //         maxi=max(maxi,dp[i]);
    //     }
    //     return maxi;
    // }



    //LIC using binary search
     int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            
            }
            else {
              int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind]=nums[i];

            }
        }
        return temp.size();
     }

};