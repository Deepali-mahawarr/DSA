class Solution {
public:
vector<int>prefix(vector<int>&arr){
    int n=arr.size();
    vector<int>s1(n);
    s1[0]=arr[0];
    for(int i=1;i<n;i++){
        s1[i]=max(s1[i-1],arr[i]);
    }
    return s1;
}
vector<int>sufix(vector<int>&arr){
    int n=arr.size();
    vector<int>s2(n);
    s2[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        s2[i]=max(s2[i+1],arr[i]);
    }
    return s2;
}

    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre=prefix(arr);
        vector<int>suff=sufix(arr);
        int total=0;
        for(int i=0;i<n;i++){
            int leftmax=pre[i];
            int rightmax=suff[i];
            if(arr[i]<leftmax && arr[i]<rightmax)
            total+=min(leftmax,rightmax)-arr[i];

        }
        return total;

        
    }
};