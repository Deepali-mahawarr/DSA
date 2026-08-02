class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int maxi=*max_element(arr1.begin(),arr1.end());
       vector<int>freq(maxi+1);
       for(auto ele:arr1){
        freq[ele]++;
       }
       vector<int>res;
       for(auto it:arr2){
        while(freq[it]>0){
            res.push_back(it);
            freq[it]--;
        }
       }
       for(int i=0;i<=maxi;i++){
        while(freq[i]>0){
            res.push_back(i);
            freq[i]--;
        }
       }
       return res;


       
        
    }
};