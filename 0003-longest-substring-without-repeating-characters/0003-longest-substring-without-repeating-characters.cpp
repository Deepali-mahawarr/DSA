class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     int n=s.size();
    //     vector<int>freq(256,0);
    //     int i=0;
    //     int r=0;
    //     int maxlen=0;
    //     while(r<n){
    //         while(freq[s[r]]!=0){
    //             freq[s[i]]=0;
    //             i=i+1;
    //         }
    //        int len=r-i+1;
    //         maxlen=max(maxlen,len);
    //         freq[s[r]]=1;
    //         r++;

    //     }
    //     return maxlen;
        
    // }
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       vector<int>freq(256,-1);
       int l=0;
       int r=0;
       int maxlen=0;
       while(r<n){
        if(freq[s[r]]!=-1){
            if(freq[s[r]]>=l){
                l=freq[s[r]]+1;
            }
        }
        maxlen=max(maxlen,r-l+1);
        freq[s[r]]=r;
        r++;
       }
       return maxlen;
        
    }
};