class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
       // map<pair<int,int>,int>mpp;
       int mini=INT_MAX;
        vector<vector<int>>ans;
        int i=0;
        int j=1;
        while(j<n){
        int diff=arr[j]-arr[i];
         mini=min(mini,diff);
        i++;
        j++;
        }
        int l=0;
        int r=1;
        while(r<n){
            if(arr[r]-arr[l] == mini){
            ans.push_back({arr[l],arr[r]});
            }

            l++;
            r++;
        }
        return ans;


         
    }
};