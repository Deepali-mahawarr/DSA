class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string a=strs[0];
        string b=strs[n-1];
        int a1=a.size();
        int b1=b.size();
        string ans="";
        for(int i=0;i<min(a1,b1);i++){
            if(a[i]!=b[i])
            return ans;
            ans+=a[i];

        }
        return ans;
    }
};