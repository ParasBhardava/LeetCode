class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>ans;
        
        for(auto &it: nums)
            ans.push_back(to_string(it));
        
        sort(ans.begin(), ans.end(), [&](string &a, string &b){
            return a + b > b + a;
        });
        
        string res = "";
        for(auto &it: ans)
            res += it;
        
        while(res.size() > 1 && res[0] == '0')
        {
            res.erase(0, 1);
        }
        
        return res;
    }
};