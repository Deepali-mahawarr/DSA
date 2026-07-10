class Solution {
public:
int findsum(vector<int>& arr,int mid){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)arr[i]/(double)mid);
         }
    return sum;

}
    int smallestDivisor(vector<int>& arr, int threshold) {
        int n=arr.size();
        int low=1;
         int high=*max_element(arr.begin(),arr.end());
    
        while(low<=high){
            long long  mid=low+(high-low)/2;
            if(findsum(arr,mid)>threshold){
                low=mid+1;

            }
            else{
                high=mid-1;

            }
        }
        return low;
        
    }
};