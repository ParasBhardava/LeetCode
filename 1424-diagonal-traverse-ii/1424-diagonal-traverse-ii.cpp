class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n = nums.size();
        int maxKey = 0;
        unordered_map<int, vector<int>> mp;
        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = 0; col < nums[row].size(); col++)
            {
                mp[row + col].push_back(nums[row][col]);
                maxKey = max(maxKey, row + col);
            }
        }
        
        vector<int> res;
        for (int key = 0; key <= maxKey; key++)
        {
            for (auto it : mp[key])
                res.push_back(it);
        }
        return res;
    }
};