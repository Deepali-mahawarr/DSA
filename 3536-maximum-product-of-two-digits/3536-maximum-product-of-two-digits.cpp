class Solution {
public:
    int maxProduct(int n) {
        int ind=0;
        int maxi=INT_MIN;
        vector<int>arr;
        while(n>0){
            int digit=n%10;
            arr.push_back(digit);
            n=n/10;


        }
        if(arr.size()<2) return 0;
        
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                maxi = max(maxi, arr[i] * arr[j]);
            }
        }
        return maxi;
        
    }
};