class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        long long  sum=0;
        long long  mul=1;

        while(n){
            int digit=n%10;
            sum+=digit;
            mul=mul*digit;
            n=n/10;

        }
       int p=sum+mul;
       if(num%p==0) return true;
       return false;
    }
};