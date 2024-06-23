class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int left = m, right = 0, top = n, bottom = 0; 
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }
        
        int area = (right - left + 1) * (bottom - top + 1);
        return area;
    }
};