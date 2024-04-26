class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = n-2; i >=0; i--)
        {
            for(int j = 0; j < m; j++)
            {
                int ele = grid[i][j];
                grid[i][j] = INT_MAX;
                for(int k = 0; k < m; k++)
                {
                    if(k == j)
                        continue;
                    
                    grid[i][j] = min(grid[i][j], ele + grid[i+1][k]);
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i<m; i++)
            ans = min(ans, grid[0][i]);
        
        return ans;
    }
};