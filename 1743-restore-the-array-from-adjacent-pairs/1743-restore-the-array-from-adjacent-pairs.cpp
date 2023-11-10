class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    
        unordered_map<int, vector<int>> pairs;
        for (auto &pair : adjacentPairs)
        {
            pairs[pair[0]].push_back(pair[1]);
            pairs[pair[1]].push_back(pair[0]);
        }
        
        vector<int> res;
        for (auto &it : pairs) 
        {
            if (it.second.size() == 1)
            {
                res.push_back(it.first);
                res.push_back(it.second[0]);
                break;
            }
        }
        
        
        while (res.size() < adjacentPairs.size() + 1)
        {
            int last = res.back();
            int prev = res[res.size() - 2];
            auto &nexts = pairs[last];
            if (nexts[0] != prev)
                res.push_back(nexts[0]);
            else
                res.push_back(nexts[1]);
        }
        
        return res;
    }
};