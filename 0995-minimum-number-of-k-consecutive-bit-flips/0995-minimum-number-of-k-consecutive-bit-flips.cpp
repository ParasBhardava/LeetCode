class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size(), res = 0;
        queue<int> flips;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != (flips.size() % 2 ? 0 : 1))
            {
                res++;
                flips.push(i + k - 1);
            }
            
            if (!flips.empty() && flips.front() <= i)
                flips.pop();
        }
        
        if(!flips.empty())
            res = -1;
        
        return res;
    }
};