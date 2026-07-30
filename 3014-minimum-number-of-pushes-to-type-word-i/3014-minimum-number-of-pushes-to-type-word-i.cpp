class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int cnt=n/8;
        int rem=n%8;
        long long ans=0;
        for(int i=1;i<=cnt;i++){
            ans+=8*i;


        }
        ans+=rem*(cnt+1);
        return ans;
        
    }
};