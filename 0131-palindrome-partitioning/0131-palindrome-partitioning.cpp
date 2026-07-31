class Solution {
public:
bool ispalin(string s,int low,int high){
    int n=s.size();
    while(low<=high){
        if(s[low++]!=s[high--]){
            return false;
        }
    }
    return true;
}
void solve(int ind,string s,vector<string>&ds,vector<vector<string>>&res){
    if(ind==s.size()){
        res.push_back(ds);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(ispalin(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            solve(i+1,s,ds,res);
            ds.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ds;
        solve(0,s,ds,res);
        return res;
        
    }
};