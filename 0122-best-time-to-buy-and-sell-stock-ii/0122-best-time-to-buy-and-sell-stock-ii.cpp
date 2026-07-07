class Solution {
public:
// int solve(int ind,int buy,vector<int>& prices, vector<vector<int>>&dp){
//     int n=prices.size();
//     long profit=0;
//     if(ind==n) return 0;
//     if(dp[ind][buy]!=-1) return dp[ind][buy];
//     if(buy){
//         profit=max((-prices[ind]+solve(ind+1,0,prices,dp)),(0+solve(ind+1,1,prices,dp)));

//     }
//     else{
//          profit=max((prices[ind]+solve(ind+1,1,prices,dp)),(0+solve(ind+1,0,prices,dp)));
//     }
//     return dp[ind][buy]=profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//         }


//  int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));
//         dp[n][0]=0;
//         dp[n][1]=0;
//         long long  profit=0;
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 if(buy==1){
//                   profit=max((-prices[i]+dp[i+1][0]),(0+dp[i+1][1]));

//                  }
//                 else{
//                      profit=max((prices[i]+dp[i+1][1]),(0+dp[i+1][0]));
         
//                 }
//                 dp[i][buy]=profit;

//             }
//         }
//         return dp[0][1];
//     }


// int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<int>curr(2,0);
//         vector<int>ahead(2,0);
//         ahead[0]=0;
//         ahead[1]=0;
//         long long  profit=0;
//         for(int i=n-1;i>=0;i--){
//             for(int buy=0;buy<=1;buy++){
//                 if(buy==1){
//                   profit=max((-prices[i]+ahead[0]),(0+ahead[1]));

//                  }
//                 else{
//                      profit=max((prices[i]+ahead[1]),(0+ahead[0]));
         
//                 }
//                 curr[buy]=profit;

//             }
//             ahead=curr;
//         }
//         return ahead[1];
//     }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        long long anotbuy,abuy,curnotbuy,curbuy;
        anotbuy=0;
        abuy=0;
         for(int i=n-1;i>=0;i--){
           curbuy=max((-prices[i]+anotbuy),(0+abuy));
           curnotbuy=max((prices[i]+abuy),(0+anotbuy));
           abuy=curbuy;
           anotbuy=curnotbuy;
         }
         return abuy;
    }





};