class Solution {
public:
int solve(int ind,int trans,vector<int>& prices,int k, vector<vector<int>>&dp){
    int n=prices.size();
    if(ind==n || trans==2*k)
    return 0;
    if(dp[ind][trans]!=-1) return dp[ind][trans];
    if(trans % 2 ==0){ 
    return dp[ind][trans]=max((-prices[ind]+solve(ind+1,trans+1,prices,k,dp)),(0+solve(ind+1,trans,prices,k,dp)));
    }
     return dp[ind][trans]=max((prices[ind]+solve(ind+1,trans+1,prices,k,dp)),(0+solve(ind+1,trans,prices,k,dp)));
    
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return solve(0,0,prices,k,dp);
        
    }
};