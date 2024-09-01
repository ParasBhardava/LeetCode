class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>a;
        if(m * n > original.size() || original.size() > m*n)
            return a;
        
        
        vector<vector<int>>ans(m, vector<int>(n, 0));
        
        for(int i = 0; i < original.size(); i++)
            ans[i/n][i%n] = original[i];
        
        return ans;
    }
};