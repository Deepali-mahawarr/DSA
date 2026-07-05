class Solution {
public:
    // int minInsertions(string s) {
    //     string rev=s;
    //     reverse(rev.begin(),rev.end());
    //         int size=s.size();
    //         s += '$'; //separator
    //         s+=rev; //add reverse to in str;
    //         //find the longest prefix;
    //         int n=s.size();
    //         vector<int>lps(n,0);
    //         int pref=0;
    //         int suf=1;
    //         while(suf<s.size()){
    //             //match 
    //             if(s[pref]==s[suf]){
    //         lps[suf]=pref+1;
    //         pref++;
    //         suf++;
    //     }
    //     //not match
    //     else{
    //     if(pref==0){
    
    //         suf++;
    //     }
    //     else{
    //         pref=lps[pref-1];
    //     }
    //         }

    //     }
    //     return (size-lps[n-1]);
        
    // }
    int longestCommonSubsequence(string text1, string text2) {
      
        int n=text1.size();
        int m=text2.size();
          vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // int ind1=n-1;
        // int ind2=m-1;
         for(int i=0;i<=n;i++)
         dp[i][0]=0;
       for(int j=0;j<=m;j++)
         dp[0][j]=0;
    
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(text1[i-1]==text2[j-1])
         dp[i][j]= 1+dp[i-1][j-1];
        else
         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        

            }
        }
        return dp[n][m];

       
        
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
        
    }
     int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);

     }
    };
