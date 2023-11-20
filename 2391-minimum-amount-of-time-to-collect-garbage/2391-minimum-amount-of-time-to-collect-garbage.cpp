class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        
        int n = garbage.size();
        int totm = 0;
        int totp = 0;
        int totg = 0;
        
        for(int i = 0; i < n; i++)
        {
            string s = garbage[i];
            for(char ch : s)
            {
                if(ch == 'M') totm++;
                if(ch == 'P') totp++;
                if(ch == 'G') totg++;
                
            }
        }
        
        int m = 0, p = 0, g = 0;
        if(totm != 0)
        {
            for(int i = 0; i < n; i++)
            {
                string s = garbage[i];
                for(char ch : s)
                {
                    if(ch == 'M')
                    {
                        m++;
                        totm--;
                    }
                }
                
                if(totm == 0)
                    break;
                
                m += travel[i];
            }
        }
        
        if(totp != 0)
        {
            for(int i = 0; i < n; i++)
            {
                string s = garbage[i];
                for(char ch : s)
                {
                    if(ch == 'P')
                    {
                        p++;
                        totp--;
                    }
                }
                
                if(totp == 0)
                    break;
                
                if(i != n-1)
                    p += travel[i];
            }
        }

        if(totg != 0)
        {
            for(int i = 0; i < n; i++)
            {
                string s = garbage[i];
                for(char ch : s)
                {
                    if(ch == 'G')
                    {
                        g++;
                        totg--;
                    }
                }
                
                if(totg == 0)
                    break;
                
                if(i != n-1)
                    g += travel[i];
            }
        }
        
        // cout<<m<<" "<<p<<" "<<g<<"\n";
        return m + p + g;
    }
};