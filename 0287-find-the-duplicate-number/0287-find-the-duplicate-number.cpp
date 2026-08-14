class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;

        }
        for(auto it:mpp){
            if(it.second>=2) 
            return it.first;
        }
        return -1;
        
    }
};