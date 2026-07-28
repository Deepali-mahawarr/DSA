class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int ind=n-1;
        int cnt=0;
        while(ind>=0 && s[ind]==' ') ind--;
        while( ind>=0 && s[ind]!=' '){
            cnt++;
            ind--;
        }
        return cnt;
        
    }
};