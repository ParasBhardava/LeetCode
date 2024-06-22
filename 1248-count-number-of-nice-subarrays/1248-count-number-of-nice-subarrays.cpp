class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] % 2 == 1) 
                nums[i] = 1;
            
            else 
                nums[i] = 0;
        }
                
        
        int i = 0, count = 0, sum = 0;
        unordered_map<int, int>mp;
        while(i < n)
        {
            sum += nums[i];
            
            if(sum == k)
                count++;
            
            if(mp.find(sum - k) != mp.end())
                count += mp[sum - k];
            
            mp[sum]++;        
            i++;
        }
        
        return count;
        
    }
};