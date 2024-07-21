class Solution {
    
private:
    vector<int> topoSort(int n, vector<vector<int>> &adjl)
    {
        queue<int>q;
        vector<int> indegree(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            for(auto j : adjl[i])
                indegree[j]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int>topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adjl[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            } 
        }

        return topo;
    }

    
private:
    bool checkCycle(int node, vector<vector<int>>& adjl, vector<bool>&visited, vector<bool>&dfsvisited)
{
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(auto it: adjl[node])
    {
        if(!visited[it])
        {
            if(checkCycle(it, adjl, visited, dfsvisited))
                return true;
        }

        else if(dfsvisited[it])
            return true;
    }

    dfsvisited[node] = 0;
    return false;
}

private:
bool cycleDetection(int n, vector<vector<int>>&adjl)
{
    vector<bool>visited(n + 1, false);
    vector<bool>dfsVisited(n + 1, false);

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            if(checkCycle(i, adjl, visited, dfsVisited))
                return true;
        }
    }

    return false;
}
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<vector<int>>adjl1(k + 1);
        vector<vector<int>>adjl2(k + 1);
        
        for(auto it : rowConditions)
            adjl1[it[0]].push_back(it[1]);
        
        for(auto it : colConditions) {
            adjl2[it[0]].push_back(it[1]);
        }
        
        if(cycleDetection(k, adjl1) || cycleDetection(k, adjl2)) 
            return {};
        
        vector<int>topo1 = topoSort(k, adjl1);
        vector<int>topo2 = topoSort(k, adjl2);
        
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++)
            mp[topo2[i]] = i;
        
        for(int i = 0; i < k; i++)
            res[i][mp[topo1[i]]] = topo1[i];
        
        return res;
    }
};