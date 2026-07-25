class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(sum>maxi){
                maxi=sum;

            }
            if(sum<0){
                sum=0;
            }
            // if(maxi<0){
            //     return {0} ;
            // }

        }
        return maxi;
        
    }
};
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) 
//     {
//         int sum = nums[0];
//         int maxi = nums[0];
        
//         for(int i = 1; i < nums.size(); i++ )
//         {
//             sum = max(nums[i], sum + nums[i]);

//             maxi = max(maxi, sum);

//         }

//         return maxi;
//     }
// };