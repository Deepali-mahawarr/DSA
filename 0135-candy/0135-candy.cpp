class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        int sum=1;
        int i=1;
        while(i<n){
            if(nums[i]==nums[i-1]){
                sum=sum+1;
                i++;
                //continue;
            }
        int peak=1;
            while(i<n && (nums[i]>nums[i-1])){
                peak++;
                sum=sum+peak;
                i++;
            }
            int down=1;
            while(i<n && (nums[i]<nums[i-1])){
                sum=sum+down;
                i++;
                down++;
            }
            if(down>peak){
                sum=sum+(down-peak);
            }
        }
        return sum;
        
    }
};