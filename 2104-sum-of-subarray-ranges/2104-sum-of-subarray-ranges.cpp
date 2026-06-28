class Solution {
public:
    // long long subArrayRanges(vector<int>& nums) {
    //     int n=nums.size();
    //     long long res=0;
    //     for(int i=0;i<n-1;i++){
    //         int maxi=nums[i], mini=nums[i];
    //         for(int j=i+1;j<n;j++){
    //             if(nums[j]>maxi)maxi=nums[j];
    //             else if(nums[j]<mini)mini=nums[j];
    //             res+=maxi-mini;
    //         }
    //     }
    //     return res;
    // }
    vector<int> findNSE(vector<int> arr){
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i]=st.empty() ? n :st.top();
            st.push(i);
        }
        return nse;
    }
vector<int> findNGE(vector<int> arr){
        int n=arr.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            nge[i]=st.empty() ? n :st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findPSEE(vector<int> arr){
        int n=arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            psee[i]=st.empty() ? -1 :st.top();
            st.push(i);
        }
        return psee;
    }
    vector<int> findPGEE(vector<int> arr){
        int n=arr.size();
        vector<int> pgee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            pgee[i]=st.empty() ? -1 :st.top();
            st.push(i);
        }
        return pgee;
    }
    long long sumSubarrayMins(vector<int>& arr) {
          int n=arr.size();
          vector<int> nse=findNSE(arr);
          vector<int> psee=findPSEE(arr);
          long long total=0;
          int mod=1e9+7;
          for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i]));
          }
          return total;
    }
    long long sumSubarrayMax(vector<int>& arr) {
          int n=arr.size();
          vector<int> nge=findNGE(arr);
          vector<int> pgee=findPGEE(arr);
          long long total=0;
          int mod=1e9+7;
          for(int i=0;i<n;i++){
            int left=i-pgee[i];
            int right=nge[i]-i;
            total=(total+(right*left*1LL*arr[i]));
          }
          return total;
    }


     long long subArrayRanges(vector<int>& nums){
          long long sum_min=sumSubarrayMins(nums);
          long long sum_max=sumSubarrayMax(nums);
          return sum_max-sum_min;

     }

};