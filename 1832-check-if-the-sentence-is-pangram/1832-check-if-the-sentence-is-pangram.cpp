class Solution {
public:
    bool checkIfPangram(string str) {
        vector<int>alpha(26,0);
        for(int i=0;i<str.size();i++){
            alpha[str[i]-'a']=1;
        }
        for(int i=0;i<alpha.size();i++){
            if(alpha[i]==0)
            return false;
            
        }
        return true;
    }
};