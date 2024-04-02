class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        unordered_map<char, char>mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i])
                    return false;
            }
            
            else
            {
                for(auto &it: mp)
                {
                    if(it.first != s[i] && it.second == t[i])
                        return false;
                }           
                mp[s[i]] = t[i];
            }       
        }
        
        return true;
    }
};