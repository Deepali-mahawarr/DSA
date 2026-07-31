class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        for(auto it:word){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});

        }
        int cost=0;
        int mul=1;
        int cnt=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int freq=it.first;
            char c=it.second;
            cost+=(mul*freq);
            cnt++;
            if(cnt==8){
                cnt=0;
                mul++;
            }
        }
        return cost;
        
    }
};