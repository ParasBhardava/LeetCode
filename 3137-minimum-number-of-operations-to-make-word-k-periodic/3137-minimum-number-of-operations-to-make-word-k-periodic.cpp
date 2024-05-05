class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        
        int n = word.size(), maxi = 0;
        unordered_map<string, int>mp;
        for(int i = 0; i < n; i += k)
        {
            string sub = word.substr(i, k);
            mp[sub]++;
            maxi = max(maxi, mp[sub]);
        }
        
        return n / k - maxi;
        
    }
};