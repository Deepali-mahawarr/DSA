class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int xor1=0;
        // int xor2=0; 
        int n=nums.size();
        // for(int j=0;j<n;j++){
        //     xor2=xor2^nums[j];
        //        xor1=xor1^(j+1);
        // }
        // xor1=xor1^(n);
        // return xor1^xor2;
        int s=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum =sum+nums[i];

        }
        return (s-sum);
        
    }
}; 