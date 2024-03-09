class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>s1(nums1.begin(), nums1.end());
        unordered_set<int>s2(nums2.begin(), nums2.end());

        for(int it : nums1)
        {
            if(s1.count(it) && s2.count(it))
                return it;
        }
        
        return -1;
    }
};