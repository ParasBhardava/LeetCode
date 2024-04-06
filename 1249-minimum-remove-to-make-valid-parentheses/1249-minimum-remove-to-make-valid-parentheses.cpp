class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.size();
        string ans = "";
        
        int open = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(s[i] == ')')
            {
                if(open <= 0)
                    continue;
                
                open--;
            }
            
            if(s[i] == '(')
                open++;
            
            ans.push_back(s[i]);
        }
        cout<<ans<<"\n";
        
        string res = "";
        int close = 0;
        for(int i = ans.size() - 1; i >= 0; i--)
        {
            if(ans[i] == '(')
            {
                if(close <= 0)
                    continue;
                
                close--;
            }
            
            if(ans[i] == ')')
                close++;
            
            res.push_back(ans[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};