class Solution {
    
private:
    int solve(int val, vector<int>& nums)
    {
        int count = 0;
        for(auto &it : nums)
        {
            if(it >= val)
                count++;
        }
        
        return count;
    }
    
public:
    int specialArray(vector<int>& nums) {
        
        int start = 0, end = nums.size(), mid;
        
        while(start <= end)
        {
            mid = start + (end - start)/2;
            
            int count = solve(mid, nums);
            if(count == mid)
                return mid;
            
            if(count > mid)
                start = mid + 1;
            
            else
                end = mid - 1;
        }
        
        return -1;
    }
};