class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>&arr,vector<vector<vector<int>>>&dp){
    int n=arr.size();
    if(ind==n || cap==0)
    return 0;
    if(dp[ind][buy][cap]!=-1)
    return dp[ind][buy][cap];
    
    if(buy==1){
        return dp[ind][buy][cap]=max(-arr[ind]+f(ind+1,0,cap,arr,dp),0+f(ind+1,1,cap,arr,dp));
    }
    
    return dp[ind][buy][cap]=max(arr[ind]+f(ind+1,1,cap-1,arr,dp),0+f(ind+1,0,cap,arr,dp));
    
  
}  
    long maxProfit(vector<int>& arr) {
        int n=arr.size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       return f(0,1,2,arr,dp);
        
    }
    

};
// class Solution{
// public:
// long maxProfit(vector<int>& arr) {
//         int n=arr.size();
        
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
//         int cap=0;
//         for(int ind=0;ind<n-1;ind++){
//             for(int buy=0;buy<=1;buy++){
//                 dp[ind][buy][0]=0;
//             }
//         }
//         int ind=n;
//         for(int cap=0;cap<=2;cap++){
//             for(int buy=0;buy<=1;buy++){
//                 dp[n][buy][cap]=0;
//             }
//         }

//        for(int ind=n-1;ind>=0;ind--){
//         for(int buy=0;buy<=1;buy++){
//             for(int cap=0;cap<=2;cap++){
//             if(buy)
            
//              dp[ind][buy][cap]=max(-arr[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
//              else
//              dp[ind][buy][cap]=max(arr[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);

       
//         }


//        }
//        }
       
//        return dp[0][1][1];
        
//     }
    
// };