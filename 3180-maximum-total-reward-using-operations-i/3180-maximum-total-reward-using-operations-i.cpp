class Solution {
    
private:
    int solve(int idx, int sum, int n, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(idx >= n)
            return 0;
        
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int dontTake = solve(idx + 1, sum, n, nums, dp);
        int take = 0;
        if(nums[idx] > sum)
            take = nums[idx] + solve(idx + 1, sum + nums[idx], n, nums, dp);
        
        return dp[idx][sum] = max(take, dontTake);
    }
    
public:
    int maxTotalReward(vector<int>& rewardValues) {
        set<int> s(rewardValues.begin(), rewardValues.end());
        vector<int> nums(s.begin(), s.end());
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(4000, -1));
        return solve(0, 0, n, nums, dp);
    }
};