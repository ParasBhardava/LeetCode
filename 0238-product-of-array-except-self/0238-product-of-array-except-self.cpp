class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        
        vector<int>begin(nums.size());
        vector<int>end(nums.size());
        vector<int>res(nums.size());
        begin[0] = 1;
        end[nums.size()-1] = 1;
        
        for(int  i=1; i<nums.size(); i++)
            begin[i] = begin[i-1]*nums[i-1];
        
        for(int  i=nums.size()-2; i>=0; i--)
            end[i] = end[i+1]*nums[i+1];
          
        for(int i = 0; i<nums.size(); i++)
            res[i] = begin[i] * end[i];
        
        return res;
        
    }
};