class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        long long anotbuy,abuy,curnotbuy,curbuy;
        anotbuy=0;
        abuy=0;
         for(int i=n-1;i>=0;i--){
           curbuy=max((-prices[i]+anotbuy),(0+abuy));
           curnotbuy=max(((prices[i]-fee)+abuy),(0+anotbuy));
           abuy=curbuy;
           anotbuy=curnotbuy;
         }
         return abuy;
        
    }
};