#define INF 100000000

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int inf  = 100000000;
        
        vector<vector<int>>adjm(n, vector<int>(n, inf));
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adjm[u][v] = wt;
            adjm[v][u] = wt;
        }
    
        
        vector<vector<int>>dist = adjm;

        for (int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                dist[i][i] = 0;
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int ans = 0;
        int mini = INT_MAX;
        
        vector<int>reachable(n, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || dist[i][j] == inf)
                    continue;
                
                if(dist[i][j] <= distanceThreshold)
                    reachable[i]++;
            }
            
            if(reachable[i] <= mini)
            {
                mini = reachable[i];
                ans = i;
            }
        }
        
        return ans;
    }
};