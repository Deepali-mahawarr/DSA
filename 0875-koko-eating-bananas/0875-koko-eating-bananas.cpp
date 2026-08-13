class Solution {
public:
long long  findhour(vector<int>& piles,int mid){
    int n=piles.size();
    long long total=0;
    for(int i=0;i<n;i++){
        total+=ceil(((double)piles[i]/mid));

    }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long  totalH=findhour(piles,mid);
            if(totalH<=h)
            high=mid-1;
            else
            low=mid+1;


        }
        return low;
        
    }
};