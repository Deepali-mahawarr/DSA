class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        map<long long,int>freqmpp;
        for(auto el:nums)
        freqmpp[el]++;
        for(auto [el,freq]:freqmpp){
        long long x=el;
            int cnt=0;
            while(freqmpp.find(x)!=freqmpp.end() && freqmpp[x]){
            if(x==1) cnt+=freqmpp[1];
            else if(freqmpp[x]>=2) cnt+=2;
            else if(freqmpp[x]==1){
                cnt++;
                break;
            }
            freqmpp[x]=0;
            if(x>1e6)
            break;
            x=x*x;
        }
        ans=max(ans,cnt-(cnt%2==0));
        }
        return ans;
    }
};