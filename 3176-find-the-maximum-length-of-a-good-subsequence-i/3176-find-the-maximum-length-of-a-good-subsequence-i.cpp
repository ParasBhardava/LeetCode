class Solution {
    
private:
    int solve(int idx, int prev, int remainingK, int n, vector<int> &nums, vector<vector<vector<int>>>&dp)
    {
        if(idx >= n)
            return 0; 

        if(dp[idx][prev + 1][remainingK] != -1)
            return dp[idx][prev+1][remainingK];

        int take = 0, dontTake = 0;
        
        if(prev == -1) 
        {
            dontTake = solve(idx + 1, -1, remainingK, n, nums, dp);
            take = 1 + solve(idx + 1, idx, remainingK, n, nums, dp);
        }

        else
        {
            if(nums[idx] == nums[prev])
                take = 1 + solve(idx + 1, idx, remainingK, n, nums, dp);
            
            else
            {
                dontTake = solve(idx + 1, prev, remainingK, n, nums, dp);
                if(remainingK > 0)
                    take = 1 + solve(idx + 1, idx, remainingK - 1, n, nums, dp);
            }

        }

        return dp[idx][prev + 1][remainingK] = max(take, dontTake);
    }

    
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(0, -1, k, n, nums, dp);
    }
};