class Solution {
    
private:
    long long solve(int idx, int isEven, int n, int k, vector<int>&nums,  vector<vector<long long>> &dp){
        if (idx == n)
            return isEven == 1 ? 0 : LONG_LONG_MIN;
        
        if (dp[idx][isEven] != -1)
            return dp[idx][isEven];

        long long Xor = (nums[idx] ^ k) + solve(idx + 1, !isEven, n, k, nums, dp);
        long long dontXor = nums[idx] + solve(idx + 1, isEven, n, k, nums, dp);

        return dp[idx][isEven] = max(Xor, dontXor);
    }
    
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));     
        return solve(0, 1, n, k, nums, dp);
    }
};