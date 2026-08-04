class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]=1;
        }
        vector<int>ans;
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=mini;i<maxi;i++){
            int ele=i+1;
            if(mpp.find(ele)==mpp.end()){
                ans.push_back(ele);
                
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};