class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        unordered_map<long long, long long>factors;
        for(auto num : nums1)
        {    
            for (long long factor = 1LL; factor * factor <= num; factor++)
            {
                if (num % factor == 0)
                {
                    factors[factor]++;
                    if (num / factor != factor)
                        factors[num / factor]++;
                }
            }
        }
        
        long long ans = 0LL;
        for(auto num : nums2)
            ans += factors[1LL * num * k];
        
        return ans;
    }
};