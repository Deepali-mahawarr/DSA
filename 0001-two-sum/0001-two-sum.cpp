class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int more=target-a;
            if(mpp.find(more)!=mpp.end()){
                return{mpp[more],i};
            }
            mpp[a]=i;

        }
        return {-1,-1};
        
    }
};



// class Solution{

// public:
//  vector<int> twoSum(vector<int>& nums, int target) {
//     int n=nums.size();
//     // sort(nums.begin(),nums.end());
//     int i=0;
//     int j=n-1;
//     int sum=0;
//     vector<int>ans;
//     while(i<j){
//         sum=nums[i]+nums[j];
//         if(sum==target){
//             return{i,j};
    
//         }
//         else if(sum<target)
//         i++;
//         else j--;
//     }
//     return {} ;

//  }


// };