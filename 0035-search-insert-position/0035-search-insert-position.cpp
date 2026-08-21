class Solution {
public:
    int searchInsert(vector<int>& Arr, int x) {
         // code here
        int n=Arr.size();
        
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
         if(Arr[mid]>=x){
                high=mid-1;
                
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
    }
};