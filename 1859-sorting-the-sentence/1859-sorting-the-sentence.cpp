class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(10);
        int idx=0;
        int cnt=0;
        string temp;
        while(idx<s.size()){
            if(s[idx]==' '){
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                cnt++;
            }
            else{
                temp +=s[idx];
            }
            idx++;
        }
        int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                cnt++;
                
                for(int i=1;i<=cnt;i++){
                    temp+=ans[i];
                    temp+=' ';
                
                }
                temp.pop_back();
                return temp;

//        vector<string>ans(10);
//        string temp;
//        int cnt=0;
//        int index=0;
//        while(index<s.size()){
//         if(s[index]==' '){
//             int pos=temp[temp.size()-1]-'0';
//             temp.pop_back();
//             ans[pos] = temp;
//             temp.clear();
//             cnt++;
//         }
//         else{
//             temp+=s[index];
        

//         }
//        } 
//        int pos=temp[temp.size()-1]-'0';
//             temp.pop_back();
//             ans[pos]=temp;
//             temp.clear();
//             cnt++;
    

//     for(int i=1;i<=cnt;i++){
//         temp+=ans[i];
//         temp +=' ';
//     }
// temp.pop_back();
//     return temp;
    }
};