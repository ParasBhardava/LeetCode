class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size(), count = 0, i = 0, j = 0;
        long long res = 0;
        
        while(j < n)
        {
            if(nums[j] == maxi)
                count++;
            while (count >= k)
            {
                if(nums[i] == maxi)
                    count--;
                i++;
            }
            res += i;
            j++;
        }
        return res;
    }
};