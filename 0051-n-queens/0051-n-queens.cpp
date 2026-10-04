class Solution {
public:
bool issafe(int row,int col,vector<string>ds,int n){

    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if(ds[row][col]=='Q') return false;
        row--;
        col--;

    }
     row=duprow;
     col=dupcol;
    while(col>=0){
        if(ds[row][col]=='Q') return false;
        col--;
        }
     row=duprow;
     col=dupcol;
    while(row<n && col>=0){
        if(ds[row][col]=='Q') return false;
        row++;
        col--;

    }
    return true;

}
void solve(int col,vector<vector<string>>&ans,vector<string>&ds,int n){
    if(col==n){
        ans.push_back(ds);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,ds,n)){
            ds[row][col]='Q';
            solve(col+1,ans,ds,n);
            ds[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>ds(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
        ds[i]=s;
        }
        solve(0,ans,ds,n);
        return ans;
        
    }
};