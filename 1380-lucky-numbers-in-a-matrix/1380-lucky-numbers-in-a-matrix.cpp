class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> rowMinimums(n, INT_MAX);
        vector<int> colMaximums(m, 0);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = matrix[i][j];
                rowMinimums[i] = min(rowMinimums[i], curr);
                colMaximums[j] = max(colMaximums[j], curr);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = matrix[i][j];
                if (curr == rowMinimums[i] && curr == colMaximums[j])
                    return {curr};
            }
        }
        
        return {};
    }
};