class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int, long long> prev;
        int n = nums.size();
        long long res = 0LL;
        
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, long long> next;
            next[nums[i]] = 1LL;
            
            for (auto it : prev)
                next[it.first & nums[i]] += prev[it.first];

            for (auto it : next)
            {
                if(it.first == k)
                    res += it.second;
            }
            prev = next;
        }
        
        return res;
    }
};