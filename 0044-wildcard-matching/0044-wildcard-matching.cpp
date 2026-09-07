class Solution {
public:
int f(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    if(i==0 && j==0)
    return true;
    if(i==0 && j>0)
    return false;
    if(j==0 && i>0){
        for (int c=1;c<=i;c++){
            if(p[c-1]!='*') return false;
           
        }
         return true;

    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[i-1]==s[j-1] || p[i-1]=='?'){
        return dp[i][j]=f(i-1,j-1,s,p,dp);
    }
    if(p[i-1]=='*'){
        return dp[i][j]=f(i-1,j,s,p,dp)| f(i,j-1,s,p,dp);
    }
    return dp[i][j]=false;

}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,s,p,dp);
        
    }
};