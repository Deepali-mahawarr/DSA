class Solution {
public:
    string defangIPaddr(string arr) {
        int n=arr.size();
        int idx=0;
        string ans;
        while(idx<n){
            if(arr[idx]=='.'){
                ans+="[.]";

            }
            else
            ans+=arr[idx];
            idx++;
        }
        return ans;
        
    }
};