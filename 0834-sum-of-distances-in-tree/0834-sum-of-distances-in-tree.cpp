class Solution {

private:        
    void dfs1(int node, int par, vector<vector<int>>&adjl, vector<int>&subtree, vector<int>&res)
    {
        int sum = 0;
        for(auto it : adjl[node])
        {
            if(it == par)
                continue;
            
            dfs1(it, node, adjl, subtree, res);
            sum += subtree[it];
            res[node] += res[it] + subtree[it];
        }

        subtree[node] = 1 + sum;
    }

    void dfs2(int node, int par, int n, vector<vector<int>>&adjl, vector<int>&subtree, vector<int>&res) 
    {
        for(auto it : adjl[node])
        {
            if(it == par)
                continue;
            
            res[it] = (res[node] - subtree[it]) + (n - subtree[it]);
            dfs2(it, node, n, adjl, subtree, res);
        }
    }

public:  
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjl(n);
        vector<int>subtree(n, 0);
        vector<int>res(n, 0);
        for(int i = 0; i < n - 1; i++)
         {
            int u = edges[i][0];
            int v = edges[i][1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }

        dfs1(0, -1, adjl, subtree, res);
        dfs2(0, -1, n, adjl, subtree, res);
        return res;
    }

};