// class Solution {
// public:
//     string removeDuplicates(string s) {
//         int n=s.size();
//         stack<char>st;
//         for(int i=0;i<n;i++){
//             char ch=s[i];
//             if(!st.empty() && st.top()==ch){
//                 st.pop();

//             }
//            else
//             st.push(ch);
//         }
//         string ans="";
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
       
//     }
// };


class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        string ans="";

        // ans=ans+s[0];
        for(int i=0;i<n;i++){
            if( !ans.empty() && ans.back()==s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};