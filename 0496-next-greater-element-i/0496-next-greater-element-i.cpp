// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
//       vector < int > nge(n1, -1);
//       int res;
//       stack < int > st;
//       for(int i=0;i<n1;i++){
//         res=nums1[i];
// }
//       for(int i=n2-1;i>=0;i--){
//       while(!st.empty() && st.top()<=res)
//         st.pop();
//         if(st.empty())
//         nge[i]= -1
//         else 
//         nge[i]=st.top();
//         st.push(res);        
//     }
//     return nge;
// // int n1 = nums1.size();
// // int n2 = nums2.size();
// // map<int,int>nge;
// // stack<int>st;
// // vector<int>result;
// // for(int i=n2-1;i>=0;i--){
// //     while(!st.empty() && st.top() <=nums2[i]){
// //         st.pop();

// //     }
// //     if(st.empty())
// //     nge[nums2[i]]=-1;
// //     else
// //     nge[nums2[i]]=st.top();
// //     st.push(nums2[i]);

// //     }
// //     for(int j :nums1){
// //         result.push_back(nge[j]);
// //     }
// //     return result;
//     }
// };

class Solution {
 public:
     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>mpp;
        stack<int>st;
        vector<int>ans(n1);
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])  st.pop();
            mpp[nums2[i]]=st.empty()? -1:st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n1;i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
     }
};