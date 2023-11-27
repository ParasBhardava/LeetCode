class Solution {
    
private:
    private :
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
            }

            else
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

    };
    
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
     
        int n = nums.size();
        vector<pair<int, int>>arr;
        DSU dsu(n);
        
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});
        
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++)
        {
            if(arr[i].first - arr[i - 1].first <= limit)
                dsu.Union(arr[i].second, arr[i - 1].second);
        }
        
        unordered_map<int, vector<int>>mp;
        for(int i = 0 ; i < n; i++)
            mp[dsu.findParent(i)].push_back(i);
        
        for(auto &it : mp)
        {
            vector<int>temp;
            for(auto &idx : it.second)
                temp.push_back(nums[idx]);
            sort(temp.begin(), temp.end());
            
            int k = 0;
            for(auto &idx : it.second)
                nums[idx] = temp[k++];
        }
        
        return nums;
    }
};