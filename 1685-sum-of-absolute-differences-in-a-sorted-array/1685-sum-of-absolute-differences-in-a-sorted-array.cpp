class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>pre(n, 0);
        vector<int>ans(n, 0);
        
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = nums[i] + pre[i-1];
        
        
        for(int i = 0; i < n; i++)
        {
            int before = (nums[i] * (i+1)) - pre[i];
            int after = (pre[n-1] - pre[i]) - ((n - 1 - i) * nums[i]);
            
            ans[i] = before + after;
        }
        
        return ans;
    }
};