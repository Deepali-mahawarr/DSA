class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n=hand.size();
        map<int,int>mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        while(!mpp.empty()){
            int curr=mpp.begin()->first;
            for(int i=0;i<gs;i++){
                if(mpp[curr+i]==0) return false;
                mpp[curr+i]--;
                if(mpp[curr+i]<1)
                mpp.erase(curr+i);
            }
        }
        return true;
        
    }
};