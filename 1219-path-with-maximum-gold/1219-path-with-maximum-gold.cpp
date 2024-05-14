class Solution {
    
private:
    vector<int>dx = {0, 1, 0, -1};
    vector<int>dy = {1, 0, -1, 0};
    
private:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid) 
    {
        if (i < 0 || i == n || j < 0 || j == m || grid[i][j] == 0)
            return 0;
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxi = 0;
        for (int k = 0; k < 4; k++)
            maxi = max(maxi, solve(i + dx[k], j + dy[k], n, m, grid));
        grid[i][j] = gold;
        return gold + maxi;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                maxi = max(maxi, solve(i, j, n, m, grid));
        }
        return maxi;
    }
};