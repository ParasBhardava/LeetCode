class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>res;
        
        for(int i = 1; i <= n - 2; i++)
        {
            vector<int>ans;
            for(int j = 1; j <= n - 2; j++)
            {
                int maxi = 0;
                for(int x = -1; x <= 1; x++)
                {
                    for(int y = -1; y <= 1; y++)
                    {
                        maxi = max(maxi, grid[i + x][j + y]);
                    }
                }
                ans.push_back(maxi);
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};