class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, vector<vector<int>>&res)
    {
        queue<pair<int, int>>q;
        q.push({i, j});
        land[i][j] = 0;
        
        int coord[2][2] = {{0, 1}, {1, 0}};
        int ex = i, ey = j;
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k = 0; k < 2; k++)
            {
                int dx = x + coord[k][0];
                int dy = y + coord[k][1];
                
                if(dx >=0 && dx < land.size() && dy >=0 && dy < land[0].size() && 
                   land[dx][dy] == 1)
                {
                    land[dx][dy] = 0;
                    q.push({dx, dy});
                    
                    ex = max(ex, dx);
                    ey = max(ey, dy);
                }
            }
            
            
        }
        
        res.push_back({i, j, ex, ey});
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>>res;
        vector<vector<int>>l = land;
        
        
        for(int i = 0; i<l.size(); i++)
        {
            for(int j = 0; j<l[0].size(); j++)
            {
                if(l[i][j] == 1)
                {
                    dfs(l, i, j, res);
                }
            }
        }
        
        return res;
    }
};