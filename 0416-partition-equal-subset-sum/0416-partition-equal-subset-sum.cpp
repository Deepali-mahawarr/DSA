class Solution {
public:

bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
      for(int i=0;i<n;i++){
          dp[i][0]=1;
      }
      if(arr[0]<=sum){
          dp[0][arr[0]]=1;
      }
      for(int i=1;i<n;i++){
          for(int target=0;target<=sum;target++){
          bool pick=false;
      if(arr[i]<=target)
      pick=dp[i-1][target-arr[i]];
      bool notpick=dp[i-1][target];
      dp[i][target]=pick||notpick;
          }
      }
      return dp[n-1][sum];
      
          
      }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
            }
            if(totalsum%2==1) return false;
            return isSubsetSum(nums,totalsum/2);
            
    }
};