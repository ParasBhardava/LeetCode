class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = l.size();
        vector<bool> res;
        for(int i = 0; i < n; i++)
        {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            
            int j = 0;
            for (j = 2; j < temp.size(); j++)
            {
                if (temp[j] - temp[j - 1] != temp[1] - temp[0])
                    break;
            }
            
            res.push_back(j == temp.size());
        }
        
        return res;
    }
};