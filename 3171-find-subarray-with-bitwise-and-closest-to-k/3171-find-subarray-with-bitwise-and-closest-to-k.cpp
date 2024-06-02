class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        unordered_set<int> prev;
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> next;
            next.insert(nums[i]);
            for (int it : prev)
                next.insert(it & nums[i]);

            for (int it : next)
                res = min(res, abs(k - it));

            prev = next;
        }
        return res;
    }
};