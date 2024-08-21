class Solution {
    
private:
    int solve(int i, int j, string &s, vector<vector<int>>&dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1) 
            return dp[i][j];

        int x = i;
        while(x + 1 <= j && s[x] == s[x + 1])
            x++;
        
        int ans = 1 + solve(x + 1, j, s, dp);

        for(int k = x + 1; k <= j; k++)
        {
            if(s[k] == s[i])
                ans = min(ans, solve(k, j, s, dp) + solve(x + 1, k - 1, s, dp));
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }
};