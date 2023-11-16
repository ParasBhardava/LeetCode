class Solution {
    
    string solve(int idx, string str, unordered_set<string>&s, int n)
    {
        if(idx == n)
        {
            if(s.find(str) == s.end())
                return str;
            
            return "";
        }
        
        string ans;
        ans = solve(idx + 1, str + '0', s, n);
        
        if(ans != "")
            return ans;
        
        ans = solve(idx + 1, str + '1', s, n);
        
        return ans;
    }
    
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>s;
        
        for(auto &it: nums)
            s.insert(it);
        
        return solve(0, "", s, n);
    }
};