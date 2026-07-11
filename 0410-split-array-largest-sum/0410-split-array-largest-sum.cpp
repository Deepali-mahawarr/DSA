class Solution {
  public:
  int cntstudent(vector<int>&arr,long long mid){
      int n=arr.size();
      int cntstu=1;
      int pagestu=0;
      for(int i=0;i<n;i++){
          if(arr[i]+pagestu <= mid){
              pagestu+=arr[i];
          }
          else{
              cntstu++;
              pagestu=arr[i];
              
          }
          
          
      }
      return cntstu;
  }
   int splitArray(vector<int>& arr, int k) {
    // int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
         int low=*max_element(arr.begin(),arr.end());
        long long  high=accumulate(arr.begin(),arr.end(),0LL);
         while(low<=high){
             long long  mid=low+(high-low)/2;
             if(cntstudent(arr,mid)>k)
             low=mid+1;
             else 
             high=mid-1;
         }
         return low;
}


   
};