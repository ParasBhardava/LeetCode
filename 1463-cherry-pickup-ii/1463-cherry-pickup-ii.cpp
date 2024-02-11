class Solution {

private:
    int solve(int r, int c1, int c2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp)
    {
        if(r == grid.size())
            return 0;
        
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int ans = 0;
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                int newC1 = c1 + i;
                int newC2 = c2 + j;
                
                if(newC1 >= 0 && newC1 < grid[0].size() && newC2 >= 0 && newC2 < grid[0].size())
                {
                    ans = max(ans, solve(r + 1, newC1, newC2, grid, dp));
                }
                
            }
        }
        
        if(c1 == c2)
            ans += grid[r][c1];
        
        else
            ans += grid[r][c1] + grid[r][c2];
        
        return dp[r][c1][c2] = ans;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        vector<vector<vector<int>>>dp(71, vector<vector<int>>(71, vector<int>(71, -1)));
        int n = grid.size(), m = grid[0].size();
        return solve(0, 0, m-1, grid, dp);
    }
};