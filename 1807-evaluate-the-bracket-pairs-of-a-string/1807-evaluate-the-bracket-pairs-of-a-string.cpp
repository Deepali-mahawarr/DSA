class Solution {
public:
    string evaluate(string s, vector<vector<string>>& kd) {
        int n=s.size();
        int m=kd.size();
        unordered_map<string,string>mpp;
        for(auto &it:kd){
           mpp[it[0]]=it[1]; 

        }

        bool addkey=false;
        string key,res;
       for(char c:s){
        if(c=='('){
            addkey=true;
        }
        else if(c==')'){
            if(mpp.count(key)>0){
                res+=mpp[key];
            }
            else{
                res.push_back('?');
            }
            addkey=false;
            key.clear();
        }
        else if(addkey)
        key+=c;
        else
        res.push_back(c);
       }

       return res; 
        
    }
};