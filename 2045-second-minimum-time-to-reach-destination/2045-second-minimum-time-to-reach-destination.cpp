class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
       vector<vector<int>>adjl(n + 1);
        int firstArrivedTime = INT_MAX;
        
        for(auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        
        queue<vector<int>> q;
        q.push({1, 0});
        vector<int> visTime(n + 1, INT_MAX);
        vector<int> visCount(n + 1, 0);
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it[0], t1 = it[1];
            for(int next : adjl[node])
            {
                int t2 = t1;
                bool isRed = (t2 / change) % 2;
                if(isRed)
                    t2 += change - t2 % change;
                t2 += time;
                
                if(next == n && firstArrivedTime == INT_MAX) 
                    firstArrivedTime = t2;
                
                if(next == n && t2 > firstArrivedTime)
                    return t2;
                
                if(visTime[next] != t2 && visCount[next] <= 1) 
                {
                    visTime[next] = t2;
                    visCount[next]++;
                    q.push({next, t2});
                }
            }
        }
        return -1;
    }
};