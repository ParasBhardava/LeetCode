class Solution {
    
private:
    int solve(int limit, vector<vector<int>>& grid, int n)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        if (grid[0][0] <= limit)
            return false;
        
        q.push({0, 0});
        vis[0][0] = true;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x == n - 1 && y == n - 1)
                return true;
            
            for(int k = 0; k < 4; k++)
            {
                int newX = (x + dx[k]);
                int newY = (y + dy[k]);
                
                if(newX >= 0 && newY >= 0 && newX < n && newY < n && grid[newX][newY] > limit && !vis[newX][newY])
                {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        return false;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int, int>> q;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid.size();++j)
            {
                if(grid[i][j])
                    q.push({i, j});
            }
        }

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++)
            {
                int newX = (x + dx[k]);
                int newY = (y + dy[k]);
                
                if(newX >= 0 && newY >= 0 && newX < n && newY < n &&
                   (grid[newX][newY] == 0 || grid[x][y] + 1 < grid[newX][newY]))
                {
                    grid[newX][newY] = (grid[x][y] + 1);
                    q.push({newX, newY});
                }
            }
        }
        
        int start = 0, end = 400, mid, ans = 0;
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            
            if(solve(mid, grid, n))
            {
                ans = mid;
                start = mid + 1;
            }
            
            else
                end = mid - 1;
        }
        
        return ans;
    }
};