// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int size=0;
//         int open=0;
//         for(char &ch:s){
//             if(ch=='('){
//                 size++;
//       }
//             else if(size>0){
//                 size--;
//             }
//             else{
//                 open++;
//             }
//         }
//         return open+size;
        
//     }
// };


class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        for(char &ch:s){
            if(ch=='('){
                open++;
      }
            else if(open>0){
                open--;
            }
            else{
                close++;
            }
        }
        return open+close;
        
    }
};