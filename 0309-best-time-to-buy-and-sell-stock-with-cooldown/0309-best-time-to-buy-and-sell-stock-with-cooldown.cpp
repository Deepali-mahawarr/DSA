class Solution {
public:
// int solve(int ind,int buy,vector<int>& prices, vector<vector<int>>&dp){
//     int n=prices.size();
//     long profit=0;
//     if(ind>=n) return 0;
//     if(dp[ind][buy]!=-1) return dp[ind][buy];
//     if(buy){
//         profit=max((-prices[ind]+solve(ind+1,0,prices,dp)),(0+solve(ind+1,1,prices,dp)));

//     }
//     else{
//          profit=max((prices[ind]+solve(ind+2,1,prices,dp)),(0+solve(ind+1,0,prices,dp)));
//     }
//     return dp[ind][buy]=profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//          vector<vector<int>>dp(n,vector<int>(2,-1));
//          return solve(0,1,prices,dp);
        
//     }



    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> front2(2,0),front1(2,0),curr(2,0);

        for(int ind=n-1;ind>=0;ind--){

            curr[1]=max(-prices[ind]+front1[0],0+front1[1]);
            curr[0]=max(prices[ind]+front2[1],0+front1[0]);


            front2=front1;
            front1=curr;
        }

        return curr[1];
    }
};