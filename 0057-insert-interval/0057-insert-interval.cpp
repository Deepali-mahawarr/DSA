class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newi) {
        int n= interval.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<n &&  interval[i][1]<newi[0]){
            ans.push_back( interval[i]);
            i++;
        }
        while(i<n &&  interval[i][0]<=newi[1]){
            newi[0]=min( interval[i][0],newi[0]);
            newi[1]=max( interval[i][1],newi[1]);
            i++;
        }
        ans.push_back(newi);
        while(i<n){
            ans.push_back( interval[i]);
            i++;
        }
        return ans;
        
    }
};