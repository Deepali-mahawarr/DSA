// class Solution {
// public:
//  void permu(vector<int>&freq,vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
//     if(ds.size()==nums.size()){
//         ans.push_back(ds);
//     }
//     for(int i=0;i<nums.size();i++)
//     {
//         if(!freq[i]){
//             ds.push_back(nums[i]);
//             freq[i]=1;
//             permu(freq,nums,ds,ans);
//             freq[i]=0;
//             ds.pop_back();
//         }

//     }
//      }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>ds;
//         int n=nums.size();
//         vector<int>freq(n,0);

        
//         permu(freq,nums,ds,ans);
//         return ans;

        
//     }
// };
class Solution{
    void funn(int ind,vector<int>&nums,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            funn(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    funn(0,nums,ans);
    return ans;
  }

};