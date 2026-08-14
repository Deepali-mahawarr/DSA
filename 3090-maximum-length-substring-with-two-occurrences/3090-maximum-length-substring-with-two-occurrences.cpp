class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int maxlen=INT_MIN;
        unordered_map<char,int>mpp;
        while(j<n){
            mpp[s[j]]++;
            while( i<j && mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;

        
    }
};