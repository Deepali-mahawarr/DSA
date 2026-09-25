class Solution {
public:

 bool ispalindrome(string &s,int i,int j){
        int n=s.size();
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;

        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
       int cnt=0;

         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                   cnt++;
                }
            }
         }
         return cnt;
        
    }
};