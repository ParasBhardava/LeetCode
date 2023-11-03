class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string>res;
        int curr = 1;
        for(int i = 0; i < target.size(); i++)
        {
            while(curr != target[i])
            {
                res.push_back("Push");
                res.push_back("Pop");
                curr++;
            }
            res.push_back("Push");
            curr++;
        }
        
        return res;
    }
};