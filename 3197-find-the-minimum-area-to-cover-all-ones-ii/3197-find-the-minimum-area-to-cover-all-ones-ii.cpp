class Solution {
private:
    int minimumArea(vector<vector<int>>& grid, int start_i, int start_j, int end_i, int end_j)
    {    
        int n = grid.size(), m = grid[0].size();
        int left = m, right = 0, top = n, bottom = 0;
        bool flag = false;
        
        for(int i = start_i; i <= end_i; i++)
        {
            for(int j = start_j; j <= end_j; j++)
            {
                if(grid[i][j] == 1)
                {
                    flag = true;
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }
        
        if(!flag)
            return 0;
        
        int area = (right - left + 1) * (bottom - top + 1);
        return area;
    }
    
public:
    int minimumSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), res = INT_MAX;
        vector<vector<vector<vector<int>>>>area(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0))));
        
        // Calculating area for each reactangle
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int p = i; p < n; p++)
                {
                    for(int q = j; q < m; q++)
                        area[i][j][p][q] = minimumArea(grid, i, j, p, q);
                }       
            }
        }
        
        
        /*
        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------
        */
        for(int i = 0; i < n; i++)
        {
            int first = area[0][0][i][m - 1];
            for(int j = 0; j < m; j++)
            {
                int second = area[i + 1][0][n - 1][j];
                int third = area[i + 1][j + 1][n - 1][m - 1];
                res = min(res, first + second + third);
            }
        }
        
        /*
        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
        */
        for(int j = 0; j < m; j++)
        {
            int first = area[0][0][n - 1][j];
            for(int i = 0; i < n;i++)
            {
                int second = area[0][j + 1][i][m - 1];
                int third = area[i + 1][j + 1][n - 1][m - 1];
                res = min(res, first + second + third);
            }
        }
        
        
        /*
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------
        */
        for(int j = m - 1; j >= 0; j--)
        {
            int first = area[0][j + 1][n - 1][m - 1];
            for(int i = 0; i < n; i++)
            {
                int second = area[0][0][i][j];
                int third = area[i + 1][0][n - 1][j];
                res = min(res, first + second + third);
            }
        }
        
        /*
        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------
        */
        for(int i = n - 1; i >= 0; i--)
        {
            int first = area[i + 1][0][n - 1][m - 1];
            for(int j = 0; j < m; j++)
            {
                int second = area[0][0][i][j];
                int third = area[0][j + 1][i][m - 1];
                res = min(res, first + second + third);
            }
        }
        
         /*
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
        */
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int first = area[0][0][i][m - 1];
                int second = area[i + 1][0][j][m - 1];
                int third = area[j + 1][0][n - 1][m - 1];
                res = min(res, first + second + third);
            }
        }
        
        /*
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        */        
        for(int i = 0; i < m; i++)
        {
            for(int j = i + 1; j < m; j++)
            {
                int first = area[0][0][n - 1][i];
                int second = area[0][i + 1][n - 1][j];
                int third = area[0][j + 1][n - 1][m - 1];
                res = min(res, first + second + third);
            }
        }
        
        return res;
    }
};