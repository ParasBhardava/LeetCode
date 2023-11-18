class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int i=0, j=0, ans = 0;
        long long int sum = 0;
        sort(nums.begin(), nums.end());
        
        while(j < nums.size())
        {
            sum += nums[j];
                
            if((long long)nums[j]*(j-i+1) <= sum+k)
            {
                ans = max(ans, j-i+1);
                j++;
            }
            
            else if((long long)nums[j]*(j-i+1) > sum + k)
            {
                while((long long)nums[j]*(j-i+1) > sum + k)
                {
                    sum -= nums[i];
                    i++;
                }
                
                j++;
            }
        }
        
        return ans;
    }
};