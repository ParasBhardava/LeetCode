class Solution {
    
private:
    long long solve(int idx, int sign, int n, vector<int>& nums, vector<vector<long long>>&dp)
    {
        if(idx >= n)
            return 0;
        
        if(dp[idx][sign] != -1)
            return dp[idx][sign];
        
        long long res = LONG_LONG_MIN;
        
        // Start new subaray
        res = max(res, nums[idx] + solve(idx + 1, 1, n, nums, dp));
        
        // Continue with old subarray
        if(sign)
            res = max(res, -1 * nums[idx] + solve(idx + 1, 0, n, nums, dp));
        else
            res = max(res, nums[idx] + solve(idx + 1, 1, n, nums, dp));
        
        return dp[idx][sign] = res;
    }
    
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n, vector<long long>(2, -1LL));
        return solve(0, 0, n, nums, dp);
    }
};