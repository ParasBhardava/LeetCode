class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int>prefix = {0};
        int idx = 0;
        
        for(int i = 1; i < n; i++){
            
            if(nums[i - 1] % 2 == nums[i] % 2)
                idx++;
            
            prefix.push_back(idx);
        }
        
        vector<bool>res;
        for(auto query : queries){
            res.push_back(prefix[query[0]] == prefix[query[1]]);
        }
        
        return res;
    }
};