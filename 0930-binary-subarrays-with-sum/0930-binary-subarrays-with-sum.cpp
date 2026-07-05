class Solution {
public:
int fun(vector<int>& nums,int goal){
    int n=nums.size();
    int l=0;
    int r=0;
    int cnt=0;
    int sum=0;
    while(r<n){
        sum+=nums[r];
        while(l<=r && sum>goal){
            sum=sum-nums[l];
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
        }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        if(goal<0) 
        return 0;
        return fun(nums,goal)-fun(nums,goal-1);
        
    }
};