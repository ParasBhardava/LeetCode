class Solution {

private:
    const int MOD = 1000000007;
    int dp[100001][2][3];
    
private:
    int solve(int idx, int absent, int late, int n)
    {
        if(idx == n)
            return 1;
        
        if(dp[idx][absent][late] != -1)
            return dp[idx][absent][late];
        
        int ans = 0;
        
        // 'P'
        ans = (ans % MOD + solve(idx + 1, absent, 0, n) % MOD) % MOD;
            
        // 'A'
        if(absent == 0)
            ans = (ans % MOD + solve(idx + 1, 1, 0, n) % MOD) % MOD;
        
        // 'L'
        if(late != 2)
            ans = (ans % MOD + solve(idx + 1, absent, late + 1, n) % MOD) % MOD;
        
        return dp[idx][absent][late] = ans;
    }
    
public:
    int checkRecord(int n) {
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n);
    }
};