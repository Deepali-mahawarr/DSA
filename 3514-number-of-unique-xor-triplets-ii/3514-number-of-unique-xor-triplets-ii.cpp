class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);
        vector<bool> ans(MAXX, false);

        int n = nums.size();

        // Compute all possible pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        // Combine each number with every possible pair XOR
        for (int num : nums) {
            for (int x = 0; x < MAXX; x++) {
                if (pairXor[x]) {
                    ans[num ^ x] = true;
                }
            }
        }

        int count = 0;
        for (bool x : ans)
            if (x) count++;

        return count;
    }
};