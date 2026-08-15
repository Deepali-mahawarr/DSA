class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int el,nse,pse;
        stack<int>st;
        int area=0;
        for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i] ){
            el=st.top();
            st.pop();
            nse=i;
            pse=st.empty()? -1:st.top();
             area=max(area,arr[el]*(nse-pse-1));

        }
        st.push(i);
        } 
         while(!st.empty()){
            nse=n;
            el=st.top();
            st.pop();
               pse=st.empty()? -1:st.top();
        
            area=max(area,arr[el]*(nse-pse-1));

            
         }
         return area;
        
    }
};