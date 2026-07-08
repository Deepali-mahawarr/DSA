class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mpp(26,0);
        for(auto it:tasks){
            mpp[it-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(mpp[i])
            pq.push(mpp[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                auto freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
            }
            for(auto &f:temp){
                if(f>0)
                pq.push(f);
            }
            if(pq.empty())
            time+=temp.size();
            else 
            time=time+(n+1);
            }
            return time;
        
    }
};