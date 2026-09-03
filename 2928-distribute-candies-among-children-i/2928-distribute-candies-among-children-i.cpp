class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans=0;
        for(int child1=0;child1<=limit;child1++){
            for(int child2=0;child2<=limit;child2++){
                for(int child3=0;child3<=limit;child3++){
                    if(child1+child2+child3==n){
                        ans=ans+1;
                    }
                }
            }
        } 
        return ans;       
    }
    
};