// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         long long ans=1;
//         int n=nums.size();
//         int maxi=INT_MIN;
   
//         for(int i=0;i<n-2;i++){
//             for(int j=i+1;j<n-1;j++){
//                 for(int k=j+1;k<n;k++){
//                     ans=nums[i]*nums[j]*nums[k];
//                     if(ans>maxi)
//                     maxi=ans;
//                 }
//             }
//         }
//         return maxi;
        
        
//     }
// };
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int result1=nums[n-1]*nums[n-2]*nums[n-3];
        int result2=nums[0]*nums[1]*nums[n-1];

        return max(result1,result2);

        
    }
};