class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     
        if(k <= 1)
            return 0;
        
        int j = 0, i = 0, mul = 1, count = 0;
        
        while(j < nums.size())
        {
            mul *= nums[j];
            
                while(mul >= k)
                {
                    mul /= nums[i];
                    i++;
                }

            count += j-i+1;
            j++;
        }
        
        return count;
    }
};