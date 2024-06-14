class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i-1])
            {
                res += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }
};