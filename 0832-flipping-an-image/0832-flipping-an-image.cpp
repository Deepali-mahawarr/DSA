class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>newone(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                newone[i][j]=1;
                else
                newone[i][j]=0;
            }
        }
        return newone;

        
    }
};