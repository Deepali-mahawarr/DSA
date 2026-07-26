class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int start=arr[i][0];
            int end=arr[i][1];
            if(!ans.empty() && ans.back()[1]>=end) continue; //The previous merged interval already extends beyond the current interval.
            for(int j=i+1;j<n;j++){
                if(arr[j][0]<=end){
                    end=max(end,arr[j][1]);


                }
                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
        


















//         sort(arr.begin(),arr.end());
//         vector<vector<int>>ans;
//         for(int i=0;i<arr.size();i++){
//             if(ans.empty() || arr[i][0]>ans.back()[1]){
//                 ans.push_back(arr[i]);
//             }
//             else{
//                 ans.back()[1]=max(ans.back()[1],arr[i][1]);

//             }
//         }
//         return ans;
//     }
// };
