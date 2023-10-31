class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int n = pref.size();
        vector<int>ans(n);
        ans[0] = pref[0];
        int prevXor = ans[0];
        
        for(int i = 1; i < n; i++)
        {
            ans[i] = pref[i] ^ prevXor;
            prevXor = prevXor ^ ans[i];
        }
        
        return ans;
    }
};