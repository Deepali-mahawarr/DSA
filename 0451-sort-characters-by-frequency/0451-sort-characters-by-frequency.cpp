class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> map;
        for(int i=0;i<n;i++){
            map[s[i]]++;
        }

        priority_queue<pair<int,char>> pq;
        
       for(auto it: map){
         pq.push({it.second,it.first});
       }

       string ans="";  
       while(!pq.empty()){
          auto it= pq.top();
          pq.pop(); 
          int cnt=it.first;
          char ch=it.second;
          ans.append(cnt, ch);
       }
       return ans;
    }
};