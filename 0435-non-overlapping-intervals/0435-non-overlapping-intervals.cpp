class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),[](vector<int> &a, vector<int> &b){
                return a[1]<b[1];
        });

        int cnt=1;
        int lastending=arr[0][1];
        for(int i=1;i<n;i++){
            if(lastending<=arr[i][0]){
                cnt++;
                lastending=arr[i][1];
            }
        }

        return n-cnt;

    }
};