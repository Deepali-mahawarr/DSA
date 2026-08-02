// class Solution {
// public:
//     int winningPlayerCount(int n, vector<vector<int>>& pick) {
      
//         vector<int>freq(n,0);
//         for(auto it:pick){
//         int player=it[0];
//         int color=it[1];
//           if(freq[player]==0){
//             freq[player]=color;

//           }
//           else if(freq[player]==color){
//             freq[player]++;
//           }

//         }
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             if(freq[i]>=i+1)
//             cnt++;

//         }
//         return cnt;
        
//     }
// };

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& nums) {
        int m=nums.size();
        map<pair<int,int>,int> mpp;
        vector<int> vis(n,0);
        for(auto &it: nums){
            mpp[{it[0],it[1]}]++;
        }

        int ans=0;
        for(auto &it: mpp){
            pair<int,int> node=it.first;
            int freq=it.second;
            if(freq>node.first && vis[node.first]==0){
                ans++;
                vis[node.first]=1;
            }
        }
        return ans;
    }
};