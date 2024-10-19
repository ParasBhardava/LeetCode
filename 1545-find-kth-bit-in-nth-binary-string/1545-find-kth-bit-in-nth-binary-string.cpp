class Solution {
    
    string solve(string &s)
    {
        string ans = "";
        int n = s.size();
        for(int i =  n - 1; i >= 0; i--)
        {
            if(s[i] == '1')
                ans.push_back('0');
            
            else
                ans.push_back('1');
        }
        
        return ans;
    }
    
public:
    char findKthBit(int n, int k) {
        
        string prev = "0";
        string curr;
        for(int i = 1; i <= n; i++)
        {
            string curr = prev;
            curr.push_back('1');
            curr += solve(prev);
            
            // cout<<curr<<" ";
            prev = curr;
        }
        
        return prev[k-1];
        
    }
};