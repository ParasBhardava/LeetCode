class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long ans = -1;
        for (int num : nums)
        {
            if (num < sum)
                ans = num + sum;
        
            sum += num;
        }
        return ans;
    }
};