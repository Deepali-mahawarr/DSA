class Solution {
public:
    string sortSentence(string s) {
        int n=s.size();
        vector<string>ans(10);
        int ind=0;
        int cnt=0;
        string temp;
        while(ind<s.size()){
            if(s[ind]==' '){
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                cnt++; 
            }
            else{
                temp+=s[ind];
            }
            ind++;
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

        
    }
};