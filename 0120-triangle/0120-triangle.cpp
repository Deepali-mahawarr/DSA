class Solution {
public:
// int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
//     int n=arr.size();
//     if(i==n-1) return arr[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int right=INT_MAX;
//     int down=INT_MAX;
//     right=arr[i][j]+solve(i+1,j+1,arr,dp);
//     down=arr[i][j]+solve(i+1,j,arr,dp);

//     dp[i][j]= min(right,down);
//     return dp[i][j];

// }
//     int minimumTotal(vector<vector<int>>& arr) {
//         int n=arr.size();
        
//         vector<vector<int>>dp(n,vector<int>(n,-1));
        
//         return solve(0,0,arr,dp);
        
//     }


    //  int minimumTotal(vector<vector<int>>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     int i=0;
    //     for(int j=0;j<n;j++){
    //             dp[n-1][j]=arr[n-1][j];
    //         }
    //     for(int i=n-2;i>=0;i--){
    //     for(int j=0;j<=i;j++){
    //     //    
    //       int right=arr[i][j]+dp[i+1][j+1];
    //        int down=arr[i][j]+dp[i+1][j];
    //        dp[i][j]=min(right,down);
    //     }
    // }
    // return dp[0][0];
    //  }


     int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int>prev(n,0);
        
        for(int j=0;j<n;j++){
                prev[j]=arr[n-1][j];
            }
        for(int i=n-2;i>=0;i--){
            
        for(int j=0;j<=i;j++){
        //     int right=INT_MAX;
        //    int down=INT_MAX;
          int right=arr[i][j]+prev[j+1];
           int down=arr[i][j]+prev[j];
           prev[j]=min(right,down);
        }
    }
    return prev[0];
     }
};
