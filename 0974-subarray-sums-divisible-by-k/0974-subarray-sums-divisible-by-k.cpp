class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int res = 0;
        unordered_map<int, int>mp;
        int sum = 0;
        for(auto &it: nums)
        {
            sum += it;
            int rem = sum % k;
            if(rem < 0)
                rem += k;

            if(rem == 0)
                res++;
            
            if(mp.find(rem) != mp.end())
            {
                res += mp[rem];
            }
            
            mp[rem]++;
        }
        
        return res;
    }
};