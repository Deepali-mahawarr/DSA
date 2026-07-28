class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> nums=board;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ele=board[i][j];
                    int zero=0;
                    int one=0;
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        if(p==0 && q==0) continue;
                        int row=i+p;
                        int col=j+q;
                        if(row>=0 && row<n && col>=0 && col <m && board[row][col]==1 ) one++;
                        if(row>=0 && row<n && col>=0 && col <m && board[row][col]==0 ) zero++;
                    }
                }

                if(ele==1){
                    if(one<2) nums[i][j]=0;
                    if(one==2 || one==3) nums[i][j]=1;
                    if(one>3) nums[i][j]=0;
                }
                else{
                    if(one==3) nums[i][j]=1;
                }
            }
        }

        board=nums;
        
    }
};