class Solution {
public:
   int findtotal(int mid,int m,int k,vector<int>&arr){
    int n=arr.size();
    int bqt=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=mid){
            cnt++;
            if(cnt==k){
                bqt++;
                cnt=0;
            }
        }
        else 
        cnt=0;

    }
    return bqt;

   }
    int minDays(vector<int>& arr, int m, int k) {
        int  n=arr.size();
        int low=*min_element(arr.begin(),arr.end());
         int high=*max_element(arr.begin(),arr.end());
         if((long long) n < (long long) m*k) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bqt=findtotal(mid,m,k,arr);
            if(bqt>=m)
            high=mid-1;
            else 
            low=mid+1;

        }
        return low;
        
    }
};