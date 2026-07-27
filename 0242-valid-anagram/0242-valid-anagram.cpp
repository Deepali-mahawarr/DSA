class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a1(26,0);
         if(s.size() != t.size())
            return false;
        for(int i=0;i<s.size();i++){
            a1[s[i]-'a']++;
             a1[t[i]-'a']--;

        }
         
        for(int i=0;i<a1.size();i++){
            if(a1[i]!=0)
            return false;

        }
        return true;

        
    }
};