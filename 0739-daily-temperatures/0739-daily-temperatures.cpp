class Solution {
public:
    vector<int> dailyTemperatures(vector<int>&nums) {
        int n=nums.size();
         vector<int>nge(n,0);
         stack<int>st;
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])
            st.pop();
            if(!st.empty())
            nge[i]=st.top()-i;
            st.push(i);

         }
         return nge;
    

//          for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[j]>nums[i]){
//                     int res=j-i;
//                     ans[i]=res;
//                     break;
                    

//                 }
//                }
//                 }

//  return ans;
        
    }
};