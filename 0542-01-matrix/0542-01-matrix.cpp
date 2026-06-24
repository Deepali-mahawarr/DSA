class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else
                vis[i][j]=0;
            }

        }
        int dr[4]={0,0,1,-1};
        int dc[4]={-1,1,0,0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int steps=it.second;
            dist[row][col]=steps;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol]=1;
                    
                 }
            }
        }
        return dist;
        
    }
};