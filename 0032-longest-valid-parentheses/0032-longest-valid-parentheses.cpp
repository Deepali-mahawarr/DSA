class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        vector<int>vec={-1};
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            vec.push_back(i);
            else{
                vec.pop_back();
                if(vec.empty())
                vec.push_back(i);
                  res=max(res,i-vec.back());
            }
        }
        return res;
        
    }
};