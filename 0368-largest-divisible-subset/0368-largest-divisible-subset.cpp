class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
        int lastind=0;
        vector<int>dp(n,1),hash(n);
        sort(arr.begin(),arr.end());
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++){
                if(arr[ind]%arr[prev]==0 && 1+dp[prev]>dp[ind]){
                    dp[ind]=1+dp[prev];
                    hash[ind]=prev;
                }
                
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastind=ind;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            temp.push_back(arr[lastind]);
        }
        reverse(temp.begin(),temp.end());
       return temp;
        
    }
};