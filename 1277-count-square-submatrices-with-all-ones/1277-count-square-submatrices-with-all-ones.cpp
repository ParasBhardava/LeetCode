class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int dp[matrix.size()][matrix[0].size()], sum = 0;
        
        for(int i = 0; i<matrix.size(); i++)
        {
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        }
        
        for(int j = 1; j<matrix[0].size(); j++)
        {
            dp[0][j] = matrix[0][j];
            sum += dp[0][j];
        }
        
        for(int i = 1; i<matrix.size(); i++)
        {
            for(int j = 1; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] != 0)
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    sum += dp[i][j];
                }
                
                else
                    dp[i][j] = 0;
            }
        }
        
        return sum;
    }
};