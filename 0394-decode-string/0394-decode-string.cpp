// class Solution {
// public:
// string decode(int &i,string &s){
//     string res="";
//     int n=s.size();
//     int num=0;
//     while(i<n){
//         char ch=s[i];

//         if(isdigit(ch)){
//             num=num*10+(ch-'0');
//             i++;
//             }
           
//             else if(s[i]=='['){
//             i++;
//              string inner=decode(i,s);
//             for(int k=0;k<num;k++)
//                 res+=inner;
                
//                 num=0;
            
//             }
//            else if(s[i]==']'){
            
//             i++;
//             return res;
//            }
//             else{
//                 res+=ch;
//                 i++;
//             }


//     }
//     return res;
// }
//     string decodeString(string s) {
//         int n=s.size();
//         int i=0;
//         return decode(i,s);
        
//     }
// };


class Solution {
public:
string solve(int &i,string s){
    int n=s.size();
    int num=0;
    string ans="";
    while(i<n){
        char ch=s[i];
        if(isdigit(ch)){
            num=num*10+(ch-'0');
            i++;
        }
        else if(ch=='['){
            i++;
            string temp=solve(i,s);
            for(int k=0;k<num;k++){
                ans+=temp;
            }
            num=0;
        }
        else if(ch==']'){
             i++;
             return ans;
        }
        else{
            ans+=ch;
            i++;
        }
    }
    return ans;
}

 string decodeString(string s) {
        int n=s.size();
        int i=0;
        return solve(i,s);
        
    }

};