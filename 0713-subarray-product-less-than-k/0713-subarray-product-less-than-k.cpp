class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
       
        int l=0;
        int r=0;

        
        int  mul=1;
        while(r<n){
           
             mul=mul*nums[r];
             while(mul>=k && l<=r){
                mul=mul/nums[l];
                l++;
             }
             cnt+=(r-l+1);
             r++;
        }
        return cnt;

        
    }
};