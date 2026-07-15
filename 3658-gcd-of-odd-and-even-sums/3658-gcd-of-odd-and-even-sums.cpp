class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n==1) return 1;
        int sumodd=n*n;
        int sumeven=n*(n+1);
        return (sumeven % sumodd);
        
    }
};