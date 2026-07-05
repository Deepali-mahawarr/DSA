class Solution {
public:
int fun(vector<int>&nums,int k){
    int n=nums.size();
    int l=0;
    int r=0;
    int cnt=0;
    int sum=0;
    while(r<n){
        sum+=nums[r];
        while(l<=r && sum>k){
            sum=sum-nums[l];
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
        return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(auto &it:nums)
        it=it%2;
        return fun(nums,k)-fun(nums,k-1);
        

    }
};