class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int sqrtC = (int)sqrt(c);
        unordered_set<int>s;
        
        
        for(int i=0; i<=sqrtC; i++)
            s.insert(i*i);
        
        for(auto i : s)
        {
            if(s.find(c-i) != s.end())
                return true;
        }
        
        return false;
    }
};