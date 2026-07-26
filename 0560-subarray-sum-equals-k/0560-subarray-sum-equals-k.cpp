// class Solution {
// public:
//     int subarraySum(vector<int>& arr, int k) {
//          unordered_map<int,int>mpp;
//             mpp[0]=1;
//             int sum=0;
//             int cnt=0;
      
//         int n=arr.size();
        
//       for(int i=0;i<n;i++){
//         sum+=arr[i];
//         int rem=sum-k;
//         cnt+=mpp[rem];
//         mpp[sum]+=1;


//       }
//       return cnt;
        
//     }
// };
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mpp;
        int pre=0;
        // mpp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
           pre+=nums[i];
           if(pre==k) ans++;
           int rem=pre-k;
           ans=ans+mpp[rem];
           mpp[pre]++;
        }
        return ans;
    }
};