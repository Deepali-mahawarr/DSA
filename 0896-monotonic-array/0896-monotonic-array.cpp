class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        while(ind<n-1 && (nums[ind]<=nums[ind+1] )){
            ind++;
        }
            if(ind==n-1) return true;
            
          ind=0;
          while(ind<n-1 && (nums[ind]>=nums[ind+1])){
            ind++;
          }
            if(ind==n-1) return true;
            
          
          return false;
        
    }
};

// class Solution {
// public:
//     bool isMonotonic(vector<int>& nums) {
//         int n=nums.size();
//         bool incre=true;
//         bool dec=true;
//         for(int i=1;i<n;i++){
//             if(nums[i]<nums[i-1]){
//                 incre=false;
                
//             }
//             else if(nums[i]>nums[i-1])
//             dec=false;
//             if(!incre && !dec)
//               break;
//         }
//         return incre||dec;

//     }
// };