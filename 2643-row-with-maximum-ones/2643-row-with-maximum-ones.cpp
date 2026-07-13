class Solution {
public:
int lower_bound(vector<int>&arr,int m,int x){
    sort(arr.begin(),arr.end());
    int low=0;
    int high=m-1;
    int ans=m;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return ans;
}
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int maxcnt=-1;
        int idx=0;
        for(int i=0;i<n;i++){
            int cntones=m-lower_bound(mat[i],m,1);
             if(cntones >maxcnt){
                maxcnt=cntones;
                idx=i;
             }
        }
        vector<int>temp={idx,maxcnt};
        return temp;
        
    }
};