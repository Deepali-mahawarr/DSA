// class Solution {
// public:
// vector<int>findNse(vector<int>&arr){
//     int n=arr.size();
//     stack<int>st1;
//     vector<int>nse(n,n);
//     for(int i=n-1;i>=0;i--){
//         while(!st1.empty() && arr[st1.top()]>=arr[i])
//         st1.pop();
//         nse[i]=st1.empty()? n:st1.top();
//         st1.push(i);
//     }
//     return nse;
// }
// vector<int>findPsee(vector<int>&arr){
//     int n=arr.size();
//     stack<int>st2;
//     vector<int>pse(n,-1);
//     for(int i=0;i<n-1;i++){
//         while(!st2.empty() && arr[st2.top()]>arr[i])
//         st2.pop();
//         pse[i]=st2.empty()? -1:st2.top();
//         st2.push(i);
//     }
//     return pse;
// }
// int sumSubarrayMins(vector<int>& arr) {
//     int n=arr.size();
//         vector<int>nse=findNse(arr);
//         vector<int>pse=findPsee(arr);
//         int total=0;
//         int mod=(int)(1e9+7);
//         for(int i=0;i<n;i++){
//             int left=i-pse[i];
//             int right=nse[i]-i;
//             total =(total + ((right*left*1LL*arr[i])%mod))%mod;

//         }
//         return total;

        
//     }
// };
class Solution {
public:
    vector<int> findNse(vector<int>& arr) {
        int n = arr.size();
        stack<int> st1;
        vector<int> nse(n, n); // default is n, not -1
        for(int i=n-1;i>=0;i--) {
            while(!st1.empty() && arr[st1.top()] >arr[i])
                st1.pop();
            nse[i] = st1.empty() ? n : st1.top();
            st1.push(i);
        }
        return nse;
    }

    vector<int> findPsee(vector<int>& arr) {
        int n = arr.size();
        stack<int> st2;
        vector<int> pse(n, -1);
        for(int i=0;i<n;i++) {
            while(!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();
            pse[i] = st2.empty() ? -1 : st2.top();
            st2.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPsee(arr);
        int total = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++) {
            long left = i - pse[i];
            long right = nse[i] - i;
            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }
        return total;
}

};
