class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        
        int n = skills.size();
        int maxi = *max_element(skills.begin(), skills.end());
        unordered_map<int,int> idx;
        unordered_map<int,int> continuousWin;
        
        
        for(int i = 0; i < n; i++)
        {
            idx[skills[i]] = i;
            continuousWin[skills[i]] = 0;
        }
        
        if(k >= n)
            return idx[maxi];
        
        deque<int> dq;
        for (int i = 0; i < n; i++)
            dq.push_back(skills[i]);
        
        while(true)
        {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            
            if(a == maxi)
                return idx[a];
            
            if(b == maxi)
                return idx[b];
            
            if(a > b)
            {
                continuousWin[a]++;
                continuousWin[b] = 0;
                if(continuousWin[a] == k)
                    return idx[a];
                dq.push_back(b);
                dq.push_front(a);
            }
            else
            {
                continuousWin[b]++;
                continuousWin[a]=0;
                if(continuousWin[b] == k)
                    return idx[b];
                dq.push_back(a);
                dq.push_front(b);
            }
        }
        return 0;
    }
};