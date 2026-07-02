class Solution {
public:
// int solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
//     if(i==0 && j==0) return mat[i][j];
//     if(i<0 || j<0) return 1e9;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//   int left=INT_MAX;
//   int up=INT_MAX;
  
//        left=mat[i][j]+solve(i,j-1,mat,dp);
//      up=mat[i][j]+solve(i-1,j,mat,dp);
//      return dp[i][j]=min(left,up); 
    
// }
//     int minPathSum(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,mat,dp);
        
//     }
    //  int minPathSum(vector<vector<int>>& mat) {
    //     int n=mat.size();
    //     int m=mat[0].size();
    //     vector<vector<int>>dp(n,vector<int>(m,0));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(i==0 && j==0) dp[i][j]=mat[i][j];
    //             else{
    //                 int left=INT_MAX;
    //                 int up=INT_MAX;
    //                if(j>0) left=mat[i][j]+dp[i][j-1];
    //                 if(i>0) up=mat[i][j]+dp[i-1][j];
    //                  dp[i][j]=min(left,up);

    //             }
    //         }
    //     }
    //     return dp[n-1][m-1];
    //  }
     int minPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
             vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[j]=mat[i][j];
                else{
                    int left=INT_MAX;
                    int up=INT_MAX;
                   if(j>0) left=mat[i][j]+curr[j-1];
                    if(i>0) up=mat[i][j]+prev[j];
                     curr[j]=min(left,up);

                }
            }
            prev=curr;
        }
        return prev[m-1];
     }
};