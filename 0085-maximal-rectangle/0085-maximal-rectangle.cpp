class Solution {
public:
int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int nse;
        int pse;
        int ele;
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<n;i++)
{
    while(!st.empty() && arr[st.top()]>arr[i]){
         ele=st.top();
        st.pop();
         nse=i;
         pse=st.empty() ? -1:st.top();
        maxArea=max((arr[ele]*(nse-pse-1)),maxArea);

    }
    st.push(i);

}
while(!st.empty()){
    nse=n;
     ele=st.top();
        st.pop();
         
         pse=st.empty() ? -1:st.top();
        maxArea=max((arr[ele]*(nse-pse-1)),maxArea);    
}
return maxArea;
        
    }
    int maximalRectangle(vector<vector<char>>& mat) {
            if (mat.empty()) return 0;
          int n = mat.size();
     int m = mat[0].size();
     vector<vector<int>> psum(n, vector<int>(m));
     
     int maxArea=0;
     int sum;
     for(int j=0;j<m;j++){
        sum=0;
        for(int i=0;i<n;i++){
        sum =  (mat[i][j]=='1') ? sum+1 : 0;
        psum[i][j]=sum;
        }
 }
 for(int i=0;i<n;i++){
    maxArea=max(maxArea,largestRectangleArea(psum[i]));

 }
 return maxArea;



        
    }
};