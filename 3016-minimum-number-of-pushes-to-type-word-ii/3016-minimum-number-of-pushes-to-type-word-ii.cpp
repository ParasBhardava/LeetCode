class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> count(26, 0);
        for (char ch : word)
            count[ch - 'a']++;
        
        sort(count.begin(), count.end(), greater<int>());
        
        int ans = 0;
        for (int i = 0; i < 26; i++) 
        {
            if (count[i] == 0) 
                break;
            
            ans += (i / 8 + 1) * count[i];
        }
        
        return ans;
    }
};