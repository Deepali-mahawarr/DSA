class Solution {
public:
int mod=1e9+7;
long long mypow(long long  x,long long n){
    long long  num=n;
    if(num<0){
        x=1/x;
        num=-num;
    }
    long long ans=1;
    while(num){
        if(num%2==1)
        {
            ans=(ans*x)%mod;
            num=num-1;
        }
       
            x=(x*x)%mod;
            num=num/2;
       
        
    }
return ans;
}
    int countGoodNumbers(long long n) {
        long long e=(n+1)/2;
        long long o=n/2;
        return (long long)mypow(5,e)*mypow(4,o)%mod;

        
    }
};