class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int ans=0;

        while(i<j){
            int width=j-i;
            int h=min(arr[i],arr[j]);
            int water=width*h;
            ans=max(ans,water);
            if(arr[i]>arr[j]) j--;
            else
            i++;

        }
        return ans;
        
    }
};