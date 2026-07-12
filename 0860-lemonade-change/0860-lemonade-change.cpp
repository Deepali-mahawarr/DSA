class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int  n=arr.size();
        int five=0;
        int ten=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==5){
                five++;
                }
                else if(arr[i]==10){
                    if(five){
                    five--;
                    ten++;
                }
                else
                return false;
                }
                else{
                    if(five>0 && ten>0){
                        five--;
                        ten--;
                    }
                    else if(five>2){
                        five--;
                        five--;
                        five--;
                    }
                    else
                    return false;

                }
        }
        return true;
        
    }
};