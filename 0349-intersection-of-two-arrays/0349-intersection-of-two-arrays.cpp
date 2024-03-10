class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>ans;
        
        unordered_set<int> s(nums1.begin(), nums1.end());
        
        for (auto i : nums2)
            if (s.count(i)) {
                ans.push_back(i);
                s.erase(i);
            }
        return ans;
            
    }
};