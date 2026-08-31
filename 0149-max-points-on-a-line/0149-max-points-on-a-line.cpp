class Solution {
public:
    int maxPoints(vector<vector<int>>& num) {
      int n=num.size();
      int ans=0;
        if(n<=2) return n;
      for(auto it1:num){
      unordered_map<double,int>mpp;
        double x1=it1[0];
        double y1=it1[1];
        for(auto it2:num){
            double x2=it2[0];
            double y2=it2[1];
            double slope;
            if(it1==it2) continue;
            if(x2-x1==0) 
            slope= INT_MAX;
            else{
                slope=(y2-y1)/(x2-x1);
            }
            mpp[slope]++;
        ans=max(ans,mpp[slope]);
            
        }
      }
      return ans+1;
    }
};