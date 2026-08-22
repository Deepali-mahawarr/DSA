class Solution {
public:
void dfs(int row,int col,int &inital,int &newcolor,vector<vector<int>>&ans,vector<vector<int>>& img){
    ans[row][col]=newcolor;
     int n=img.size();
        int m=img[0].size();
        int drow[4]={0,0,1,-1};
        int dcol[4]={-1,1,0,0};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newcolor && img[nrow][ncol]==inital){
                dfs(nrow,ncol,inital,newcolor,ans,img);
        }
        }

}
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int n=img.size();
        int m=img[0].size();
        int intial=img[sr][sc];
        vector<vector<int>>ans=img;
        dfs(sr,sc,intial,color,ans,img);
        return ans;
        
    }
};