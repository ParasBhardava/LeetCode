class Solution {

private:
    const int MOD = (int)1e9 + 7;
    
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int>sum;
        for(int i = 0; i < n; i++)
        {
            int s = 0;
            for(int j = i; j < n; j++)
            {
                s += nums[j];
                sum.push_back(s);
            }
        }
        
        sort(sum.begin(), sum.end());
        
        int ans = 0;
        for(int i = left - 1; i <= right - 1; i++)
            ans = (ans % MOD + sum[i] % MOD) % MOD;
        
        return ans;
    }
};