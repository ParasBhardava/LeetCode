class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int m = arrays.size();
        int res = INT_MIN;
        int maxi = arrays[0][arrays[0].size() - 1];
        int mini = arrays[0][0];
        
        for (int i = 1; i < m; i++)
        {
            res = max(res, abs(arrays[i][0] - maxi));
            res = max(res, abs(arrays[i][arrays[i].size() - 1] - mini));
            maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
            mini = min(mini, arrays[i][0]);
        }
        
        return res;
    }
};