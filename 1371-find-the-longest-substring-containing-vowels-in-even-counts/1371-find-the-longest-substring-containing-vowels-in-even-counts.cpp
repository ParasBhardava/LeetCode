class Solution {

public:
    int findTheLongestSubstring(string s) {
        
        int n = s.size(), mask = 0, res = 0;
        
        unordered_map<char, int>vowelIdx;
        vowelIdx['a'] = 1;
        vowelIdx['e'] = 2;
        vowelIdx['i'] = 4;
        vowelIdx['o'] = 8;
        vowelIdx['u'] = 16;
        
        unordered_map<int, int>mp;
        mp[0] = -1;
        for(int i = 0; i < n; i++)
        {        
            if(vowelIdx.count(s[i]))
            {
                mask ^= vowelIdx[s[i]];
                if(!mp.count(mask))
                    mp[mask] = i;
            }
            
            res = max(res, i - mp[mask]);
        }
        
        return res;
    }
};