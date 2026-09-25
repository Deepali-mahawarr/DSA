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
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=1;
        int start=0;

         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                    if((j-i+1)>maxlen){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
         }
         return s.substr(start,maxlen);
        
    }
};