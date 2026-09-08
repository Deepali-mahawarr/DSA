class Solution {
public:
    int countCommas(int n) {
        int num=n;
        int cnt=0;
        int ans;
        while(num){
            cnt++;
            num=num/10; 
        }
        if(cnt<=3)
        return 0;
        else
        {
            ans=abs(n-999);

        }
        return ans;
        
    }
};