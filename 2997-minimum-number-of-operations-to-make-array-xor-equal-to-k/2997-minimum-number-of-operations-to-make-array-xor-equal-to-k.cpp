class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        for (int it : nums)
            k ^= it;
        
        return __builtin_popcount(k);
    }
};