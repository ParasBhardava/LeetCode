class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int t[n][n];
        memset(t, 0, sizeof(t));

        int count = 0;
        for(int i = 0; i<n; i++)
        {
            t[i][i] = 1;
            count ++;
        }

        for(int i = 0; i<n; i++)
        {
            if(s[i] == s[i+1])
            {
                t[i][i+1] = 1;
                count++;
            }
        }

        // k is length of substring
        for(int k = 3; k<=n; k++)
        {
            for(int i = 0; i<n-k+1; i++)
            {
                int j = i+k-1;

                if(s[i] == s[j] && t[i+1][j-1] == 1)
                {
                    t[i][j] = 1;
                    count++;
                }
            }
        }
        
        return count;
    }
};