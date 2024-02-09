class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int>dp(nums.size(),1);
        
        sort(nums.begin(),nums.end());
        
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j < i; j++)
            {
                if(nums[i] % nums[j]==0)
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        
        int val=0;
        
        for(int i=0; i < dp.size(); i++)
        {
            if(val<dp[i])
                val=dp[i];
        }
        
        vector<int>res;
        for(int i = dp.size()-1; i>-1; i--)
        {
            if(val == dp[i] && (!res.size() || res[res.size()-1]%nums[i] == 0))
            {
                res.push_back(nums[i]);
                val--;
            }
        }
        
        return res;
    }
};