// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         int n=nums.size();
//         double maxavg=-1e18;
       
//         for(int i=0;i<n;i++){
//         long long  sum=0;
//         for(int j=i;j<n;j++){
//             sum+=nums[j];
//             int len=(j-i+1);
//             if(len==k){
//             maxavg=max(maxavg,(double)sum/k);
//                 break;
//             }
//         }
// }
//         return maxavg;
        
//     }
// };


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
         double maxavg=-1e18;
        int l=0;
        int r=0;
        long long sum=0;
        while(r<n){
             sum=sum+nums[r];
            int len=r-l+1;
            if(len>k){
                sum=sum-nums[l];
                l++;
            }
            if(r-l+1 == k){

             maxavg=max(maxavg,(double)sum/k);
            }
             r++;

            

        }
        return maxavg;
    }
};