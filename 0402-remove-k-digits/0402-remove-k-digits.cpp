class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0')){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0') ans.pop_back();
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;

    }


    // string removeKdigits(string num, int k) {
    //     string st;

    //     for(char ch : num) {
    //         while(!st.empty() && k > 0 && st.back() > ch) {
    //             st.pop_back();
    //             k--;
    //         }
    //         st.push_back(ch);
    //     }

    //     while(k > 0) {
    //         st.pop_back();
    //         k--;
    //     }

    //     int i = 0;
    //     while(i < st.size() && st[i] == '0') i++;

    //     string ans = st.substr(i);

    //     return ans.empty() ? "0" : ans;
    // }
};