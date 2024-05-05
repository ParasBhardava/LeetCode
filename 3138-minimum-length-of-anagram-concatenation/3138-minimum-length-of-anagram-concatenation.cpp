class Solution {
    
private:
    bool solve(string &s, int k)
    {
        int n = s.size();
        vector<int>count1(26, 0);
        for(int i = 0; i < k; i++)
            count1[s[i] - 'a']++;
        
        for(int i = k; i < n; i += k)
        {
            vector<int>count2(26, 0);
            for(int j = i; j < i + k; j++)
                count2[s[j] - 'a']++;
            
            if(count1 != count2)
                return false;
        }
        
        return true;
    }
    
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for (int len = 1; len <= n; len++)
        {
            if (n % len == 0)
            {
                if(solve(s, len))
                    return len;
            }
        }
        return n;
    }
};