class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size(), i = n - 1, res = 0;
        bool flag = false;
        
        while(i >= 0 && nums[i] == 0)
        {
            flag = true;
            nums[i] = 1;
            i--;
        }
        
        if(flag)
            res++;
        
        while(i >= 0)
        {
            if(nums[i] == 0){
                res +=  2;
                while(i >= 0 && nums[i] == 0)
                {
                    nums[i] = 1;
                    i--;
                }
            }
            
            else
                i--;
        }
        
        return res;
    }
};