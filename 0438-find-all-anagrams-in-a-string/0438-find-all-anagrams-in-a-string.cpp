class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>sfreq(26,0);
        vector<int>pfreq(26,0);
        vector<int>ans;
        if(m>n) return ans;
       for(auto it:p){
        pfreq[it-'a']++;
       }
       int left=0;
    for(int right=0;right<n;right++){
        sfreq[s[right]-'a']++;
        if((right-left+1) > m){
            sfreq[s[left]-'a']--;
            left++;

        }
        //compare freq
        if((right-left+1) ==m && sfreq==pfreq)
        {
            ans.push_back(left);
        }
        
    }
    return ans;
    }
};