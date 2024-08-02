class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        
        int ones = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1) 
                ones++;
        }
        
        if(ones == 0)
            return 0;
        
        if(ones == nums.size())
            return 0;
        
        int k = 0;
        for(int i = 0; i < ones; i++)
            nums.push_back(nums[k++]);
        
        int i = 0, j = 0, mini = INT_MAX;
        int count = 0;
        while(j < nums.size())
        {
            
            count += (nums[j] == 1);
            
            if(j - i + 1 < ones)
                j++;
            
            else if(j - i + 1 == ones)
            {
                mini = min(mini, ones - count);
                if(nums[i] == 1)
                    count--;
                
                i++;
                j++;
            }
        }
        
        return mini;
        
    }
};