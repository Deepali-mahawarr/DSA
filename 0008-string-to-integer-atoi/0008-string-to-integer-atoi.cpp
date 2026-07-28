class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long ans=0;
        int sign=1;
            int i=0;
        while(i<n){
            if(s[i]==' ')
            i++;
              else break;

        }
        if(i<n &&(s[i]=='+' || s[i]=='-')){
            if(s[i]=='-')
            sign=-1;
            i++;
        }
    while(i<n && isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            i++;
            if(ans*sign<INT_MIN)
            return INT_MIN;
            if(ans*sign>INT_MAX)
            return INT_MAX;

        }
        return (ans*sign);
    }
};














// class Solution {
// public:
//     int myAtoi(string s) {
//         int i=0;
//         long ans=0;
//         int n=s.size();
//         int sign=1;
//         while(i<n){
//             if(s[i]==' ') i++;
//             else break;
//         }
  
//         if(i<n && (s[i]=='+' || s[i]=='-')){
//                 if(s[i]=='-'){
//                     sign=-1;
//                 }
//                 i++;
//         }
        
//         while(i<n && isdigit(s[i])){
//             ans=ans*10 +(s[i]-'0');
//             i++;
//             if(ans*sign<INT_MIN) return INT_MIN;
//             if(ans*sign>INT_MAX) return INT_MAX;
//         }

//         return (int)(ans*sign);
//     }
// };
