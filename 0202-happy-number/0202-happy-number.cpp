class Solution {
public:
    int new_n(int n) {
        int sum=0;
        while(n!=0){
            int i=n%10;
            n=n/10;
            sum+=i*i;
        }
        return sum;
    }
    bool isHappy(int n){
        unordered_set<int>cnt;
        while(n!=1){
            if(cnt.count(n)){
                return false;
            }
            cnt.insert(n);
            n=new_n(n);
        }
        if(n==1)return true;
        
        return false;
}
};
        