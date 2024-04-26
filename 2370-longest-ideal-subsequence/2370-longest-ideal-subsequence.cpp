class Solution {
    
int solve(int idx, int prev, int k, string &s, vector<vector<int>>&dp)
{
        if(idx == s.size())
            return 0;
        
        if(dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];
        
        int curr = s[idx] - 'a';
        int take = 0;
        if(prev == -1 || abs(curr - prev) <= k)
        {
            take = 1 + solve(idx + 1, curr, k, s, dp);
        }
        
        int dontTake = solve(idx + 1, prev, k, s, dp);
        
        return dp[idx][prev + 1] = max(take, dontTake);
}
    
public:
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(28, -1));
        return solve(0, -1, k, s, dp);   
    }
};