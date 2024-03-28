class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
    
        unordered_map<int, int> count;
        int ans = 0, i = 0, j = 0, n = nums.size();

        while(j < n)
        {
            count[nums[j]]++;
            while(count[nums[j]] > k)
            {
                count[nums[i]]--; 
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};