class Solution {
public:
int findwt(vector<int>& arr, int mid){
    int n=arr.size();
    int load=0;
    int day=1;
    for(int i=0;i<n;i++){
       
       if(arr[i]+load >mid){
        day++;
        load=arr[i];
       }
       else{
        load+=arr[i];
       }
}
    
    return day;
}
    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(findwt(arr,mid)<=days){
            high=mid-1;

        }
        else
        low=mid+1;
    }
    return low;
        
    }
};