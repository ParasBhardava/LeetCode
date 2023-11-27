class Solution {

private:
    vector<vector<int>>moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
    const int MOD = 1e9 + 7;
    
    int solve(int idx, int n, vector<vector<int>>&dp)
    {
        if(n == 0)
            return 1;
        
        if(dp[idx][n] != -1)
            return dp[idx][n];
        
        int ans = 0;
        for(auto it : moves[idx])
            ans = (ans + solve(it, n - 1, dp) % MOD) % MOD;
        
        return dp[idx][n] = ans;
    }
    
public:
    int knightDialer(int n) {
        
        int ans = 0;
        vector<vector<int>>dp(10, vector<int>(n, -1));
        for(int i = 0; i < 10; i++)
            ans = (ans + solve(i, n - 1, dp)) % MOD;
        
        return ans;
    }
};