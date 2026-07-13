class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matr, int target) {
 int n=matr.size();
        int m=matr[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matr[row][col]==target){
                return true;
            }
            else if(matr[row][col]<target){
                low=mid+1;

            }
            else{
                high=mid-1;
            }
        }
        return false;
        
    }
};