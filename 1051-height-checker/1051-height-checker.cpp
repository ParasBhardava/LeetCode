class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        unordered_map<int, int>mp;
        
        for (int height : heights)
            mp[height]++;
        
        int res = 0;
        int currHeight = 0;
        
        for (int height : heights) 
        {
            while (mp[currHeight] == 0)
                currHeight++;
            
            if (currHeight != height)
                res++;
    
            mp[currHeight]--;
        }
        
        return res;
    }
};