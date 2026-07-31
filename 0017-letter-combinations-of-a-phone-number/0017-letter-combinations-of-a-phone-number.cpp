class Solution {
public:
void solve(string dig,int i,string map[],string output,vector<string>&ans){
    if(i>=dig.length()){
        ans.push_back(output);
        return;
    }
    int number=dig[i]-'0';
    string value=map[number];
    for(int j=0;j<value.size();j++){
        output.push_back(value[j]);
        solve(dig,i+1,map,output,ans);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string dig) {
        vector<string>ans;
        if(dig.length()==0){
            return ans;
        }
        string output="";
        int i=0;
         string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(dig,i,map,output,ans);
        return ans;

    }
};