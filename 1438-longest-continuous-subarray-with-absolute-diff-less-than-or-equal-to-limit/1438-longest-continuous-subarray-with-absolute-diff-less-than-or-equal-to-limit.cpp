class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        list<int>mx;
        list<int>min;
        int i = 0, j = 0, ans= 0;
        
        while(j < nums.size())
        {
            while(mx.size() > 0 && mx.back() < nums[j])
                mx.pop_back();
            mx.push_back(nums[j]);
            
            
            while(min.size() > 0 && min.back() > nums[j])
                min.pop_back();
            min.push_back(nums[j]);
            
            if(abs(mx.front()-min.front()) <= limit)
            {
                ans = max(ans, j-i+1);
                j++;
            }
            
            else
            {
                while(abs(mx.front()-min.front()) > limit)
                {
                    if(nums[i] == min.front())
                        min.pop_front();
                    
                    if(nums[i] == mx.front())
                        mx.pop_front();
                    
                    i++;
                }
                
                j++;
            }
        }
        
        return ans;
        
    }
};