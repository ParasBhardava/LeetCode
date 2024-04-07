class Solution {

private:
    int solve(int idx, int count, int n, string &s, vector<vector<int>>&dp)
    {
        if(idx == n)
            return count == 0;

        if(dp[idx][count] != -1)
            return dp[idx][count];

        bool ans = false;
        if(s[idx] == '*')
        {
            ans |= solve(idx + 1, count + 1, n, s, dp);
            if(count > 0)
                ans |= solve(idx + 1, count - 1, n, s, dp);
            ans |= solve(idx + 1, count, n, s, dp);
        }
        
        else
        {
            if(s[idx] == '(')
                ans = solve(idx + 1, count + 1, n, s, dp);
            else
            {
                if(count > 0)
                    ans = solve(idx + 1, count - 1, n, s, dp);
            }
        }

        return dp[idx][count] = ans;
    }

public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, 0, n, s, dp);
    }
};