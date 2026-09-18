class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0;int r=0;
        int sind=-1;
        int cnt=0;
        int minlen=INT_MAX;
        unordered_map<char,int>mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0)
            cnt++;
            mpp[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minlen){
                minlen=min(minlen,r-l+1);
                sind=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)
                cnt--;
                l++;
            }

            r++;
        
        }
        if(sind==-1)
        return "";
        return s.substr(sind,minlen);
        
    }
};