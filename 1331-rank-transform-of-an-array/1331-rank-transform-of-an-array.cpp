class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         int n=arr.size();
        priority_queue<pair<int,int>,
       vector<pair<int,int>>,
       greater<pair<int,int>>>pq;
        
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        vector<int>ans(n);
        int rank=1;
        while(!pq.empty()){
            auto [val,idx]=pq.top();
            pq.pop();
            ans[idx]=rank;
            while( !pq.empty() && pq.top().first==val){
                ans[pq.top().second]=rank;
                pq.pop();
            }
            rank++;
        }
        return ans;
        
    }
};