 class DSU
{
    public:
    vector<int>parent, size;

    DSU(int n)
    {
        for(int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }


    int findParent(int node)
    {
        if(parent[node] == node)
            return  node;

        return (parent[node] = findParent(parent[node]));
    }

    void Union(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return;

        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
            size[pu] = 1;
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
            size[pv] = 1;
        }
        
    }

};


class Solution {
    
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        DSU dsu(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    dsu.Union(i, j);
                }
            }
        }
        
     
        int ans = 0;   
        for(auto &i : dsu.size)
            ans += i - 1;
            
        return ans;
    }
};