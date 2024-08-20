class Solution {

private:
    int solve(int idx, int M, vector<int>&sum, vector<vector<int>>&dp)
    {
        if(idx >= sum.size())
            return 0;
        
        if(2 * M >= sum.size() - idx)
            return sum[idx];
        
        if(dp[idx][M] != -1)
            return dp[idx][M];
            
        int mini = INT_MAX;
        for(int x = 1; x <= 2 * M; x++)
            mini = min(mini, solve(idx + x, max(M, x), sum, dp)); 
            
        return dp[idx][M] =  sum[idx] - mini;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<int>sum(n, 0);
        sum[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--)
            sum[i] = piles[i] + sum[i + 1];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 1, sum, dp);
    }
};