class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1)
            return {0};
        
        vector<int>res;
        vector<int>adjl[n];
        vector<int>degree(n, 0);
        
        for(auto &edge : edges)
        {
            adjl[edge[0]].push_back(edge[1]);
            adjl[edge[1]].push_back(edge[0]);
            
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int>q;
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 1)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int size = q.size();
            res.clear();
            
            for(int i = 0; i < size; i++)
            {
                int node  = q.front();
                q.pop();
                res.push_back(node);
                
                for(auto &i : adjl[node])
                {
                    degree[i]--;
                    
                    if(degree[i] == 1)
                        q.push(i);
                }
                
            }
        }
        
        return res;
    }
};