class Solution {
public:
  void permu(vector<int>&freq, string &ds, vector<string>&ans,int n){
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!freq[i]){
            ds.push_back(i+'0');
            freq[i]=1;
            permu(freq,ds,ans,n);
            freq[i]=0;
            ds.pop_back();
        }

    }
     }
    string getPermutation(int n, int k) {
        vector<string>ans;
        string ds="";
        vector<int>freq(n+1,0);
        permu(freq,ds,ans,n);
         return ans[k-1];

        
    }
};