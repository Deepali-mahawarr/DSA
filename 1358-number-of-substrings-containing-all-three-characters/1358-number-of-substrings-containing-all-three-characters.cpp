// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//        int lastSeen[3]={-1,-1,-1};
//         int cnt=0;
//         for(int i=0;i<s.size();i++){
//             lastSeen[s[i]-'a']=i;
//             if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
//             cnt=cnt + (1+min(lastSeen[0],lastseen[1],lastSeen[2]))
//         }
//         return cnt;
        
//     }
// };
class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int>lastseen(3,-1);
       int cnt=0;
       for(int i=0;i<s.size();i++){
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1)
            cnt=cnt+(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
}
       return cnt;
    }
};
