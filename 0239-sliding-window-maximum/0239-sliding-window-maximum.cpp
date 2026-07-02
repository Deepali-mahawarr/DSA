//  sabse phle hum ek deque lenge usme 1 ka idx jayega (0) jese he new nums[i]wo bada hoga toh deq ke piche se element nikagea jb tk wo bada rhegaa (piche se esliye kyonki aage toh sabse bada element rhegaa ha,eshaa)
//  phir hum check krenge ki hamare window k se jyda toh nhi ho gye h toh piche se hata denge ek element 
//  then push index of new element and whe i>-k-1 toh element ko list m push kr dengee 
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>list;
        deque<int>deq;
        for(int i=0;i<n;i++){
            if(!deq.empty() && deq.front() <=i-k)
            deq.pop_front();
            while(!deq.empty() && nums[deq.back()] <= nums[i])
            deq.pop_back();
            deq.push_back(i);
            if(i>=k-1) list.push_back(nums[deq.front()]);
            
        }
        return list;
    }
};