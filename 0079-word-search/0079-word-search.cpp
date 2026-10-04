class Solution {
public:
bool solve(int ind,int i,int j,vector<vector<char>>& board,string &word){
   int n=board.size();
    int m=board[0].size();
     if(ind==word.size())
    return true;
    if(i<0 ||i>=n || j<0 || j>=m || board[i][j]=='$' )
    return false;
    if(board[i][j]!=word[ind])
    return false;
    char temp=board[i][j];
    board[i][j]='$';
    int dr[4]={0,0,1,-1};
    int dc[4]={-1,1,0,0};
    for(int k=0;k<4;k++){
        int newr=i+dr[k];
        int newc=j+dc[k];
        if(solve(ind+1,newr,newc,board,word)){
            board[i][j]=temp;
            return true;
        }
    }
    board[i][j]=temp;
    return false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,board,word))
                    return true;
                }
            }
        }
        return false;
        
    }
};