// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int>temp;
//         k=k%n;
//         for(int i=n-k;i<n;i++){
//             temp.push_back(nums[i]);

//         }
//         for(int i=0;i<n-k;i++){
//             temp.push_back(nums[i]);
//         }
//         nums=temp;
        
//     }
// };
class Solution {
public:
void reverse(vector<int>&nums,int s,int e){
    while(s<=e){
        swap(nums[s],nums[e]);
        s++;
        e--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%nums.size();

        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);

        
    }
};