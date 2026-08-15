class Solution {
public:
    int evalRPN(vector<string>& arr) {
        int n=arr.size();
        
        stack<int>st;
        for(int i=0;i<n;i++){
         if(arr[i]!="+" && arr[i]!="-" && arr[i]!="*" && arr[i]!="/"  ){
            st.push(stoi(arr[i]));

         }
         else{
            int num2=st.top();
            st.pop();
            int num1=st.top();
            st.pop();
             if(arr[i]=="+"){
                st.push(num1+num2);
             }
             else if(arr[i]=="-"){
                st.push(num1-num2);
             }
             else if(arr[i]=="*"){
                st.push(num1*num2);
             }
             else{
                st.push(num1/num2);
             }
         }
        }
         return st.top();
        
    }
};