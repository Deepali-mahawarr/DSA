class Solution {
public:
bool  solve(int ind,string s, unordered_map<string,int>&mpp,vector<int>&dp){
    int n=s.size();
    if(ind==n)
    return true;
    if(dp[ind]!=-1)
    return dp[ind];
    string temp="";
    for(int i=ind;i<n;i++){
        temp+=s[i];
        if(mpp.find(temp)!=mpp.end()){
            if(solve(i+1,s,mpp,dp))
            return dp[ind]= true;
        }
    }
    return dp[ind]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_map<string,int>mpp;
        for(auto &it:wordDict){
            mpp[it]=1;
        }
         return solve(0,s,mpp,dp);
        
    }
};