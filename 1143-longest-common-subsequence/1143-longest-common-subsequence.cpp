class Solution {
public:
// int solve(int ind1,int ind2,string &t1,string &t2,vector<vector<int>>&dp){
//     int n1=t1.size();
//     int n2=t2.size();
//     if(ind1<0 || ind2<0) return 0;
//     if(dp[ind1][ind2]!=-1)
//     return dp[ind1][ind2];
//     if(t1[ind1]==t2[ind2])
//     return 1+solve(ind1-1,ind2-1,t1,t2,dp);
//      return dp[ind1][ind2]=max(solve(ind1-1,ind2,t1,t2,dp),solve(ind1,ind2-1,t1,t2,dp));
    
// }
//     int longestCommonSubsequence(string t1, string t2) {
//         int n1=t1.size();
//         int n2=t2.size();
//         vector<vector<int>>dp(n1,vector<int>(n2,-1));
//         return solve(n1-1,n2-1,t1,t2,dp);
        
//     }



    // int longestCommonSubsequence(string t1, string t2) {
    //     int n1=t1.size();
    //     int n2=t2.size();
    //     vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    //     for(int i=1;i<=n1;i++){
    //         for(int j=1;j<=n2;j++){
    //             if(t1[i-1]==t2[j-1])
    //             dp[i][j]=1+dp[i-1][j-1];
    //             else
    //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[n1][n2];
    // }


    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.size();
        int n2=t2.size();
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(t1[i-1]==t2[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }



};