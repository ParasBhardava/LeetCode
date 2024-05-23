class Solution {
    
    int solve(int idx, unordered_map<int, int> &mp, vector<int>& nums, int k)
    {
        if(idx >= nums.size())
            return 1;
        
        int dontTake = solve(idx + 1, mp, nums, k);
        
        int take = 0;
        bool flag = true;
        
        if(!mp[nums[idx] - k] && !mp[nums[idx] + k])
        {
            mp[nums[idx]]++;
            take = solve(idx + 1, mp, nums, k);
            mp[nums[idx]]--;
        }
        
        return take + dontTake;
        
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        return solve(0, mp, nums, k) - 1;
        
        
    }
};