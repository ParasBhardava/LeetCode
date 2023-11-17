class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = n-1;
        int res = 0;
        
        while(low < high)
        {
            res = max(res, nums[low] + nums[high]);
            low++;
            high--;
        }
        
        return res;
    }
};