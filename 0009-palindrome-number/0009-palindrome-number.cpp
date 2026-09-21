class Solution {
public:
    bool isPalindrome(int x) {
        
        long long n=x;
        long long revnum=0;
        if(x<0){
            return false;
        }

        while(n!=0){
             int lastdigit=n%10;
            revnum=(revnum*10)+lastdigit;
            n=n/10;

        }
        
        return (revnum==x);
            
            
        
    }

        
       

        
    
};