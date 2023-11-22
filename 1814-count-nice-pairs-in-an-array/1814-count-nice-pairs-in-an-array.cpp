class Solution {

const int MOD = 1e9 + 7;
    
private:
    int reverse(int num)
    {
        long long ans = 0;
        while(num)
        {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        
        return ans;
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int>mp;
        
        long long count = 0;
        for(int j = 0; j < n; j++)
        {
            int rev = reverse(nums[j]);
            count += mp[nums[j] - rev];
            count %= MOD;
            mp[nums[j] - rev]++;
        }
        
        return count;
    }
};